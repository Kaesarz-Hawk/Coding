package academy;

import academy.Athlete.Athlete;

public class Athletemanagement {
    public static void main(String[] args) {
        Athlete athlete1 = new Athlete();
        athlete1.setName("John Doe");
        athlete1.setAthleteId(101);
        athlete1.setPerformanceScore(85);

        System.out.println("Athlete Name: " + athlete1.getName());
        System.out.println("Athlete ID: " + athlete1.getAthleteId());
        System.out.println("Performance Score: " + athlete1.getPerformanceScore());
        System.out.println("Performance Level: " + athlete1.calculatePerformanceLevel());

        Athlete athlete2 = new Athlete();
        athlete2.setName("Jane Smith");
        athlete2.setAthleteId(102);
        athlete2.setPerformanceScore(55);

        System.out.println("\nAthlete Name: " + athlete2.getName());
        System.out.println("Athlete ID: " + athlete2.getAthleteId());
        System.out.println("Performance Score: " + athlete2.getPerformanceScore());
        System.out.println("Performance Level: " + athlete2.calculatePerformanceLevel());

        Athlete athlete3 = new Athlete();
        athlete3.setName("Mike Johnson");
        athlete3.setAthleteId(103);
        athlete3.setPerformanceScore(30);

        System.out.println("\nAthlete Name: " + athlete3.getName());
        System.out.println("Athlete ID: " + athlete3.getAthleteId());
        System.out.println("Performance Score: " + athlete3.getPerformanceScore());
        System.out.println("Performance Level: " + athlete3.calculatePerformanceLevel());

        Athlete[] athletes = { athlete1, athlete2, athlete3 };
        for (int i = 0; i < athletes.length; i++) {
            System.out.println("\nAthlete " + (i + 1) + " Details:");
            System.out.println("Name: " + athletes[i].getName());
            System.out.println("ID: " + athletes[i].getAthleteId());
            System.out.println("Performance Score: " + athletes[i].getPerformanceScore());
            System.out.println("Performance Level: " + athletes[i].calculatePerformanceLevel());
        }
    }
}
