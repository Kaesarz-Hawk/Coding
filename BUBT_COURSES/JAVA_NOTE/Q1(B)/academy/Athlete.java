package academy;

public class Athlete {
    private String name;
    private int athleteId;
    private int performanceScore;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAthleteId() {
        return athleteId;
    }

    public void setAthleteId(int athleteId) {
        this.athleteId = athleteId;
    }

    public int getPerformanceScore() {
        return performanceScore;
    }

    public void setPerformanceScore(int performanceScore) {
        if (performanceScore >= 0 && performanceScore <= 100) {
            this.performanceScore = performanceScore;
        } else {
            System.out.println("Invalid performance score.");
        }
    }

    public String calculatePerformanceLevel() {
        if (performanceScore >= 80 && performanceScore <= 100) {
            return "Elite";
        } else if (performanceScore >= 60 && performanceScore <= 79) {
            return "Advanced";
        } else if (performanceScore >= 40 && performanceScore <= 59) {
            return "intermediate";
        } else {
            return "Beginner";
        }
    }

}
