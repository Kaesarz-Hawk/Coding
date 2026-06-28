/**
 * KAESARZ: CSE WARS — Input System
 * Unified mouse + touch input handler for slingshot mechanics.
 */

export class InputManager {
    constructor(canvas) {
        this.canvas = canvas;
        this.isDown = false;
        this.isDragging = false;
        this.startPos = { x: 0, y: 0 };
        this.currentPos = { x: 0, y: 0 };
        this.lastPos = { x: 0, y: 0 };
        this.worldOffset = { x: 0, y: 0 };
        this.scale = 1;

        this.onDragStart = null;
        this.onDragMove = null;
        this.onDragEnd = null;
        this.onClick = null;
        this.onTap = null;

        this._activeTouchId = null;
        this._tapStartTime = 0;
        this._tapThreshold = 200;
        this._dragThreshold = 8;
        this._hasMoved = false;

        this._boundMouseDown = this._onMouseDown.bind(this);
        this._boundMouseMove = this._onMouseMove.bind(this);
        this._boundMouseUp = this._onMouseUp.bind(this);
        this._boundTouchStart = this._onTouchStart.bind(this);
        this._boundTouchMove = this._onTouchMove.bind(this);
        this._boundTouchEnd = this._onTouchEnd.bind(this);
        this._boundTouchCancel = this._onTouchCancel.bind(this);
        this._boundContextMenu = (e) => e.preventDefault();

        this.keys = {};
        this._boundKeyDown = this._onKeyDown.bind(this);
        this._boundKeyUp = this._onKeyUp.bind(this);

        this.enabled = true;
        this._bind();
    }

    _bind() {
        const c = this.canvas;
        c.addEventListener('mousedown', this._boundMouseDown, { passive: false });
        window.addEventListener('mousemove', this._boundMouseMove, { passive: false });
        window.addEventListener('mouseup', this._boundMouseUp, { passive: false });
        c.addEventListener('touchstart', this._boundTouchStart, { passive: false });
        window.addEventListener('touchmove', this._boundTouchMove, { passive: false });
        window.addEventListener('touchend', this._boundTouchEnd, { passive: false });
        window.addEventListener('touchcancel', this._boundTouchCancel, { passive: false });
        c.addEventListener('contextmenu', this._boundContextMenu);
        window.addEventListener('keydown', this._boundKeyDown);
        window.addEventListener('keyup', this._boundKeyUp);
    }

    destroy() {
        const c = this.canvas;
        c.removeEventListener('mousedown', this._boundMouseDown);
        window.removeEventListener('mousemove', this._boundMouseMove);
        window.removeEventListener('mouseup', this._boundMouseUp);
        c.removeEventListener('touchstart', this._boundTouchStart);
        window.removeEventListener('touchmove', this._boundTouchMove);
        window.removeEventListener('touchend', this._boundTouchEnd);
        window.removeEventListener('touchcancel', this._boundTouchCancel);
        c.removeEventListener('contextmenu', this._boundContextMenu);
        window.removeEventListener('keydown', this._boundKeyDown);
        window.removeEventListener('keyup', this._boundKeyUp);
    }

    setCamera(offsetX, offsetY, scale) {
        this.worldOffset.x = offsetX;
        this.worldOffset.y = offsetY;
        this.scale = scale;
    }

    _getCanvasPos(clientX, clientY) {
        const rect = this.canvas.getBoundingClientRect();
        const scaleX = this.canvas.width / rect.width;
        const scaleY = this.canvas.height / rect.height;
        return {
            x: (clientX - rect.left) * scaleX,
            y: (clientY - rect.top) * scaleY
        };
    }

    _getWorldPos(canvasPos) {
        return {
            x: (canvasPos.x / this.scale) + this.worldOffset.x,
            y: (canvasPos.y / this.scale) + this.worldOffset.y
        };
    }

    _onMouseDown(e) {
        if (!this.enabled) return;
        e.preventDefault();
        const pos = this._getCanvasPos(e.clientX, e.clientY);
        this._startDrag(pos);
    }

    _onMouseMove(e) {
        if (!this.enabled || !this.isDown) return;
        e.preventDefault();
        const pos = this._getCanvasPos(e.clientX, e.clientY);
        this._moveDrag(pos);
    }

    _onMouseUp(e) {
        if (!this.enabled || !this.isDown) return;
        e.preventDefault();
        const pos = this._getCanvasPos(e.clientX, e.clientY);
        this._endDrag(pos);
    }

    _onTouchStart(e) {
        if (!this.enabled) return;
        e.preventDefault();
        if (this._activeTouchId !== null) return;
        const touch = e.changedTouches[0];
        this._activeTouchId = touch.identifier;
        const pos = this._getCanvasPos(touch.clientX, touch.clientY);
        this._startDrag(pos);
    }

    _onTouchMove(e) {
        if (!this.enabled || !this.isDown) return;
        e.preventDefault();
        const touch = this._findActiveTouch(e.changedTouches);
        if (!touch) return;
        const pos = this._getCanvasPos(touch.clientX, touch.clientY);
        this._moveDrag(pos);
    }

    _onTouchEnd(e) {
        if (!this.enabled || !this.isDown) return;
        e.preventDefault();
        const touch = this._findActiveTouch(e.changedTouches);
        if (!touch) return;
        const pos = this._getCanvasPos(touch.clientX, touch.clientY);
        this._endDrag(pos);
        this._activeTouchId = null;
    }

    _onTouchCancel(e) {
        if (!this.isDown) return;
        this._activeTouchId = null;
        this.isDown = false;
        this.isDragging = false;
    }

    _findActiveTouch(touches) {
        for (let i = 0; i < touches.length; i++) {
            if (touches[i].identifier === this._activeTouchId) return touches[i];
        }
        return null;
    }

    _startDrag(pos) {
        this.isDown = true;
        this._hasMoved = false;
        this._tapStartTime = performance.now();
        this.startPos.x = pos.x;
        this.startPos.y = pos.y;
        this.currentPos.x = pos.x;
        this.currentPos.y = pos.y;
        this.lastPos.x = pos.x;
        this.lastPos.y = pos.y;

        const worldPos = this._getWorldPos(pos);
        if (this.onDragStart) {
            this.onDragStart({
                canvasX: pos.x, canvasY: pos.y,
                worldX: worldPos.x, worldY: worldPos.y
            });
        }
    }

    _moveDrag(pos) {
        this.lastPos.x = this.currentPos.x;
        this.lastPos.y = this.currentPos.y;
        this.currentPos.x = pos.x;
        this.currentPos.y = pos.y;

        const dx = pos.x - this.startPos.x;
        const dy = pos.y - this.startPos.y;
        if (dx * dx + dy * dy > this._dragThreshold * this._dragThreshold) {
            this._hasMoved = true;
            this.isDragging = true;
        }

        const worldPos = this._getWorldPos(pos);
        const worldStart = this._getWorldPos(this.startPos);
        if (this.onDragMove) {
            this.onDragMove({
                canvasX: pos.x, canvasY: pos.y,
                worldX: worldPos.x, worldY: worldPos.y,
                deltaX: pos.x - this.lastPos.x,
                deltaY: pos.y - this.lastPos.y,
                totalDeltaX: pos.x - this.startPos.x,
                totalDeltaY: pos.y - this.startPos.y,
                worldDeltaX: worldPos.x - worldStart.x,
                worldDeltaY: worldPos.y - worldStart.y
            });
        }
    }

    _endDrag(pos) {
        const worldPos = this._getWorldPos(pos);
        const elapsed = performance.now() - this._tapStartTime;

        if (!this._hasMoved && elapsed < this._tapThreshold) {
            if (this.onTap) {
                this.onTap({
                    canvasX: pos.x, canvasY: pos.y,
                    worldX: worldPos.x, worldY: worldPos.y
                });
            }
        }

        if (this.onDragEnd) {
            this.onDragEnd({
                canvasX: pos.x, canvasY: pos.y,
                worldX: worldPos.x, worldY: worldPos.y,
                wasDrag: this._hasMoved,
                startCanvasX: this.startPos.x,
                startCanvasY: this.startPos.y
            });
        }

        this.isDown = false;
        this.isDragging = false;
    }

    _onKeyDown(e) {
        this.keys[e.code] = true;
    }

    _onKeyUp(e) {
        this.keys[e.code] = false;
    }

    isKeyDown(code) {
        return !!this.keys[code];
    }

    isKeyPressed(code) {
        if (this.keys[code]) {
            this.keys[code] = false;
            return true;
        }
        return false;
    }

    /** Try to trigger haptic feedback on mobile */
    vibrate(duration = 10) {
        if (navigator.vibrate) {
            navigator.vibrate(duration);
        }
    }
}
