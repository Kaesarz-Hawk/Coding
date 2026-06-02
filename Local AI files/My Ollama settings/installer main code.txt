#!/bin/bash
echo "=== Offline Ollama + Qwen3 Setup ==="

# 1. Find the USB path
USB_PATH="$(find /media /run/media /mnt -type d -name "KAWSAR" -print -quit 2>/dev/null)"

if [ -z "$USB_PATH" ]; then
    echo "❌ Error: USB drive 'KAWSAR' not found!"
    exit 1
fi

echo "📍 Found USB at: $USB_PATH"

# 2. Copy files to home directory
echo "📂 Step 1: Copying files..."
cp "$USB_PATH/Qwen_Qwen3-8B-Q4_K_M.gguf" ~/
cp "$USB_PATH/ollama-linux-amd64.tar.zst" ~/

# 3. Install Ollama (Fixed Path Extraction)
echo "⚙️ Step 2: Extracting Ollama..."
cd ~/
sudo rm -rf /usr/local/bin/ollama /usr/local/bin/bin
sudo tar -I zstd -xf ollama-linux-amd64.tar.zst -C /usr/local/
sudo chmod +x /usr/local/bin/ollama

# 4. Create Modelfile
echo "📝 Step 3: Creating Modelfile..."
cat > ~/Modelfile << 'EOF'
FROM ./Qwen_Qwen3-8B-Q4_K_M.gguf
PARAMETER num_ctx 8192
PARAMETER temperature 0.6
PARAMETER num_thread 12
EOF

# 5. Start Service and Create Model
echo "🚀 Step 4: Initializing AI..."
sudo pkill ollama
/usr/local/bin/ollama serve &> /dev/null &
sleep 5
/usr/local/bin/ollama create qwen3-8b-coder -f ~/Modelfile

# 6. Clean up
rm -f ~/Modelfile

echo ""
echo "=========================================================="
echo "✅ SETUP COMPLETE!"
echo "You can now unplug your USB."
echo "To run the AI, execute: ollama run qwen3-8b-coder"
echo "=========================================================="