class Solution {
    // Cumulative days before the start of each month (1-indexed for convenience)
    // Month lengths: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    const vector<int> daysBeforeMonth = {
        0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
    };

    int toDayOfYear(const string& date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        return daysBeforeMonth[month] + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startA = toDayOfYear(arriveAlice);
        int endA = toDayOfYear(leaveAlice);
        int startB = toDayOfYear(arriveBob);
        int endB = toDayOfYear(leaveBob);

        int overlapStart = max(startA, startB);
        int overlapEnd = min(endA, endB);

        return max(0, overlapEnd - overlapStart + 1);
    }
};