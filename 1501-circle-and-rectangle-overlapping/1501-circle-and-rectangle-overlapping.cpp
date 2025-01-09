class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xn=max(x1,min(xCenter,x2));
        int yn=max(y1,min(yCenter,y2));

        int dx=xn-xCenter;
        int dy=yn-yCenter;

        return (dx*dx)+(dy*dy)<=(radius*radius);

    }
};