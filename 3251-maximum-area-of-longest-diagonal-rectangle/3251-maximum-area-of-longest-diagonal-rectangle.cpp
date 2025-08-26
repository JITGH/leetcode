class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
       
        double max_area=0.0;
        int diagonal_area_max=0;
        for(int i=0;i<n;i++){
                double area = sqrt((dimensions[i][0]*dimensions[i][0])+(dimensions[i][1] * dimensions[i][1]));
                int diagonal_area= dimensions[i][0]*dimensions[i][1];
                if(area>max_area){
                    diagonal_area_max = diagonal_area;
                    max_area = area;
                }
                else if(area == max_area){
                     diagonal_area_max = max(diagonal_area,diagonal_area_max);
                }

                
                
        }

        return diagonal_area_max;
    }
};