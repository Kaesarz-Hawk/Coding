/**
 * KAESARZ: CSE WARS — Material Definitions
 * Physical properties for all destructible block materials.
 */

export const MaterialType = {
    WOOD: 'wood',
    BAMBOO: 'bamboo',
    GLASS: 'glass',
    BRICK: 'brick',
    CONCRETE: 'concrete',
    STEEL: 'steel',
    ENERGY_SHIELD: 'energyShield',
    BAMBOO_MUD: 'bambooMud'
};

export const Materials = {
    [MaterialType.WOOD]: {
        name: 'Wood',
        hp: 100,
        mass: 1.0,
        restitution: 0.20,
        friction: 0.60,
        density: 1.0,
        color: '#8B6914',
        crackColor: '#5C4A1E',
        debrisColor: '#A0782C',
        breakSound: 'woodBreak',
        hitSound: 'woodHit',
        scoreMultiplier: 1.0,
        damageMultipliers: {
            red: 1.0,
            blues: 0.8,
            chuck: 2.0,
            bomb: 1.2,
            matilda: 1.0,
            hal: 1.0,
            terence: 1.5,
            bubbles: 1.0,
            stella: 0.8,
            silver: 1.0,
            ice: 0.8,
            melody: 0.9
        },
        wetDamageBonus: 1.2,
        particleColors: ['#8B6914', '#A0782C', '#6B5210', '#C49A3C']
    },
    [MaterialType.BAMBOO]: {
        name: 'Bamboo',
        hp: 70,
        mass: 0.6,
        restitution: 0.35,
        friction: 0.50,
        density: 0.6,
        color: '#6B8E23',
        crackColor: '#3D5C14',
        debrisColor: '#8FBC3C',
        breakSound: 'bambooBreak',
        hitSound: 'bambooHit',
        scoreMultiplier: 0.8,
        damageMultipliers: {
            red: 1.0,
            blues: 1.0,
            chuck: 1.8,
            bomb: 1.5,
            matilda: 1.0,
            hal: 1.0,
            terence: 2.0,
            bubbles: 1.2,
            stella: 0.8,
            silver: 1.0,
            ice: 0.8,
            melody: 1.0
        },
        wetDamageBonus: 1.2,
        particleColors: ['#6B8E23', '#8FBC3C', '#4A6B14', '#A0D050']
    },
    [MaterialType.GLASS]: {
        name: 'Glass',
        hp: 40,
        mass: 0.5,
        restitution: 0.10,
        friction: 0.30,
        density: 0.5,
        color: '#87CEEB',
        crackColor: '#4A90B0',
        debrisColor: '#B0E0F0',
        breakSound: 'glassBreak',
        hitSound: 'glassHit',
        scoreMultiplier: 0.6,
        damageMultipliers: {
            red: 1.5,
            blues: 2.0,
            chuck: 1.2,
            bomb: 1.5,
            matilda: 1.0,
            hal: 1.0,
            terence: 2.0,
            bubbles: 1.5,
            stella: 1.2,
            silver: 1.5,
            ice: 1.0,
            melody: 1.0
        },
        wetDamageBonus: 1.0,
        particleColors: ['#87CEEB', '#B0E0F0', '#5CACDE', '#E0F4FF']
    },
    [MaterialType.BRICK]: {
        name: 'Brick',
        hp: 200,
        mass: 2.0,
        restitution: 0.15,
        friction: 0.70,
        density: 2.0,
        color: '#CD5C5C',
        crackColor: '#8B3A3A',
        debrisColor: '#E08080',
        breakSound: 'brickBreak',
        hitSound: 'brickHit',
        scoreMultiplier: 1.5,
        damageMultipliers: {
            red: 0.8,
            blues: 0.5,
            chuck: 0.6,
            bomb: 2.0,
            matilda: 1.2,
            hal: 0.8,
            terence: 1.5,
            bubbles: 1.0,
            stella: 0.6,
            silver: 1.0,
            ice: 1.0,
            melody: 0.8
        },
        wetDamageBonus: 1.0,
        particleColors: ['#CD5C5C', '#E08080', '#A04040', '#F0A0A0']
    },
    [MaterialType.CONCRETE]: {
        name: 'Concrete',
        hp: 350,
        mass: 3.0,
        restitution: 0.05,
        friction: 0.80,
        density: 3.0,
        color: '#808080',
        crackColor: '#4A4A4A',
        debrisColor: '#A0A0A0',
        breakSound: 'concreteBreak',
        hitSound: 'concreteHit',
        scoreMultiplier: 2.0,
        damageMultipliers: {
            red: 0.5,
            blues: 0.3,
            chuck: 0.4,
            bomb: 1.8,
            matilda: 1.0,
            hal: 0.5,
            terence: 1.5,
            bubbles: 0.8,
            stella: 0.4,
            silver: 0.8,
            ice: 1.0,
            melody: 0.6
        },
        wetDamageBonus: 1.0,
        particleColors: ['#808080', '#A0A0A0', '#606060', '#C0C0C0']
    },
    [MaterialType.STEEL]: {
        name: 'Steel',
        hp: 500,
        mass: 4.0,
        restitution: 0.25,
        friction: 0.40,
        density: 4.0,
        color: '#708090',
        crackColor: '#404850',
        debrisColor: '#90A0B0',
        breakSound: 'steelBreak',
        hitSound: 'steelHit',
        scoreMultiplier: 3.0,
        damageMultipliers: {
            red: 0.3,
            blues: 0.2,
            chuck: 0.3,
            bomb: 1.5,
            matilda: 0.8,
            hal: 0.3,
            terence: 1.2,
            bubbles: 0.6,
            stella: 0.3,
            silver: 0.6,
            ice: 1.2,
            melody: 0.4
        },
        wetDamageBonus: 1.0,
        particleColors: ['#708090', '#90A0B0', '#506070', '#B0C0D0']
    },
    [MaterialType.ENERGY_SHIELD]: {
        name: 'Energy Shield',
        hp: 150,
        mass: 0.1,
        restitution: 0.95,
        friction: 0.00,
        density: 0.1,
        color: '#00FFFF',
        crackColor: '#008888',
        debrisColor: '#80FFFF',
        breakSound: 'shieldBreak',
        hitSound: 'shieldHit',
        scoreMultiplier: 2.5,
        damageMultipliers: {
            red: 0.5,
            blues: 0.5,
            chuck: 0.5,
            bomb: 2.0,
            matilda: 1.5,
            hal: 0.5,
            terence: 1.0,
            bubbles: 0.8,
            stella: 0.5,
            silver: 0.8,
            ice: 2.0,
            melody: 0.5
        },
        wetDamageBonus: 1.0,
        particleColors: ['#00FFFF', '#80FFFF', '#00CCCC', '#CCFFFF'],
        glowEffect: true
    },
    [MaterialType.BAMBOO_MUD]: {
        name: 'Bamboo & Mud',
        hp: 120,
        mass: 1.2,
        restitution: 0.10,
        friction: 0.75,
        density: 1.2,
        color: '#8B7355',
        crackColor: '#5C4A38',
        debrisColor: '#A08B6B',
        breakSound: 'mudBreak',
        hitSound: 'mudHit',
        scoreMultiplier: 1.2,
        damageMultipliers: {
            red: 1.0,
            blues: 0.8,
            chuck: 1.5,
            bomb: 1.8,
            matilda: 1.0,
            hal: 1.0,
            terence: 1.8,
            bubbles: 1.2,
            stella: 0.8,
            silver: 1.0,
            ice: 0.8,
            melody: 1.0
        },
        wetDamageBonus: 1.3,
        particleColors: ['#8B7355', '#A08B6B', '#6B5540', '#C0A880']
    }
};

/** Get material properties by type */
export function getMaterial(type) {
    return Materials[type] || Materials[MaterialType.WOOD];
}

/** Calculate damage based on impulse, bird type, and material */
export function calculateDamage(impulse, birdType, materialType, isWet = false) {
    const mat = getMaterial(materialType);
    const multiplier = mat.damageMultipliers[birdType] || 1.0;
    const wetBonus = isWet ? mat.wetDamageBonus : 1.0;
    return impulse * multiplier * wetBonus;
}
