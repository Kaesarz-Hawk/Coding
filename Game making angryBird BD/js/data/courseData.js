/**
 * KAESARZ: CSE WARS — BUBT CSE Course Data
 * Course names and flavor text for boss fights and level themes.
 */

export const Courses = {
    CSE101: {
        code: 'CSE 101',
        name: 'Computer & Programming Concepts',
        shortName: 'Intro to Programming',
        bossName: 'PROGRAMMING GOBLIN',
        bossQuote: '"Your code has 47 syntax errors... I counted!"',
        bossQuoteBn: '"তোমার কোডে ৪৭টা syntax error... আমি গুনে দেখেছি!"',
        world: 1
    },
    CSE103: {
        code: 'CSE 103',
        name: 'Discrete Mathematics',
        shortName: 'Discrete Math',
        bossName: 'DISCRETE TROLL',
        bossQuote: '"Prove by contradiction that you can pass this level!"',
        bossQuoteBn: '"Contradiction দিয়ে prove করো যে তুমি এই level pass করতে পারবে!"',
        world: 2
    },
    CSE231: {
        code: 'CSE 231',
        name: 'Data Structures',
        shortName: 'Data Structures',
        bossName: 'DATA STRUCTURE BEAST',
        bossQuote: '"NULL POINTER? In MY linked list?"',
        bossQuoteBn: '"NULL POINTER? আমার linked list এ?"',
        world: 3
    },
    CSE241: {
        code: 'CSE 241',
        name: 'Algorithms',
        shortName: 'Algorithms',
        bossName: 'ALGORITHM OVERLORD',
        bossQuote: '"Your solution is O(n!) and I am NOT impressed."',
        bossQuoteBn: '"তোমার solution হলো O(n!) আর আমি মোটেও impressed না!"',
        world: 4
    },
    CSE207: {
        code: 'CSE 207',
        name: 'Database Systems',
        shortName: 'Database',
        bossName: 'DATABASE HYDRA',
        bossQuote: '"SELECT * FROM students WHERE grade = F;"',
        bossQuoteBn: '"SELECT * FROM students WHERE grade = F;"',
        world: 5
    },
    CSE309: {
        code: 'CSE 309',
        name: 'Operating Systems',
        shortName: 'OS',
        bossName: 'OPERATING SYSTEM TANK',
        bossQuote: '"Process terminated. Reason: INSUFFICIENT_SKILL"',
        bossQuoteBn: '"Process terminated. Reason: INSUFFICIENT_SKILL"',
        world: 6
    },
    CSE323: {
        code: 'CSE 323',
        name: 'Compiler Design',
        shortName: 'Compilers',
        bossName: 'COMPILER DRAGON',
        bossQuote: '"Unexpected token at line 1. Actually, your ENTIRE code is unexpected."',
        bossQuoteBn: '"Line 1 এ unexpected token. আসলে তোমার পুরো code টাই unexpected!"',
        world: 7
    },
    CSE319: {
        code: 'CSE 319',
        name: 'Computer Networks',
        shortName: 'Networks',
        bossName: 'NETWORK HYDRA',
        bossQuote: '"Connection timed out. Just like your academic career."',
        bossQuoteBn: '"Connection timed out. তোমার academic career এর মতোই!"',
        world: 8
    },
    CSE351: {
        code: 'CSE 351',
        name: 'Artificial Intelligence',
        shortName: 'AI',
        bossName: 'AI EMPEROR',
        bossQuote: '"I predicted your moves before you made them. ML is beautiful."',
        bossQuoteBn: '"তোমার move করার আগেই predict করেছি। ML সুন্দর জিনিস!"',
        world: 9
    },
    CSE498: {
        code: 'CSE 498',
        name: 'Project/Thesis',
        shortName: 'Thesis',
        bossName: 'CAPSTONE DEMON',
        bossQuote: '"Your thesis proposal has been REJECTED. For the fifth time."',
        bossQuoteBn: '"তোমার thesis proposal REJECT হয়েছে। পঞ্চম বারের মতো!"',
        world: 10
    }
};

/** Banglish humor messages for defeat screen */
export const DefeatMessages = [
    "Bhai, pigs er GPA tomar cheye beshi hoye gelo!",
    "CGPA 0.00 — New record! 🎉",
    "Pig professors are now laughing in SQL.",
    "Assignment submit korte parli na? Level o parbi na!",
    "Git push --force kore level ta restart kor!",
    "Etar jonno kono Stack Overflow answer nai, bhai.",
    "Error 404: Skill not found.",
    "Segmentation Fault: Core dumped. Tomar skills o.",
    "Compile error: Too many mistakes in main().",
    "Runtime Exception: PlayerSkillNotFoundException"
];

/** Banglish humor messages for victory screen */
export const VictoryMessages = [
    "AC! Accepted! Dean's List confirmed! 🏆",
    "Pigs failed the course! You passed with flying colors!",
    "CGPA rising... scholarship loading...",
    "Senior year is looking good, bhai! 💪",
    "Professor pig is crying in the corner.",
    "Thesis approved! Convocation incoming!",
    "You just debugged an entire fortress!",
    "Clean code, clean victory. Uncle Bob would be proud.",
    "git commit -m 'destroyed pig fortress' ✅",
    "Algorithm complexity: O(WIN)"
];

/** Level intro messages per world */
export const WorldIntros = {
    1: {
        title: 'MIRPUR MOHOLLA',
        titleBn: 'মিরপুর মহল্লা',
        subtitle: 'Where every rickshaw ride is an adventure',
        subtitleBn: 'যেখানে প্রতিটি রিকশার রাইড একটি অ্যাডভেঞ্চার',
        description: 'The Pig Professors have set up shop in the narrow lanes of Mirpur. Time to launch some birds through the apartment buildings!'
    },
    2: {
        title: 'BUBT CAMPUS',
        titleBn: 'বিইউবিটি ক্যাম্পাস',
        subtitle: 'Computer labs under siege',
        subtitleBn: 'কম্পিউটার ল্যাব অবরুদ্ধ',
        description: 'The pigs have taken over the CSE department! Your birds must reclaim the lecture halls and free the lab computers!'
    }
};
