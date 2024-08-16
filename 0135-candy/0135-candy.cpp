class Solution {
public:
    int candy(vector<int>& ratings) {
        // TC -> O(3N)
        // int n=ratings.size();
        // vector<int>left(n);
        // vector<int>right(n);
        // left[0]=1;
        // right[n-1]=1;
        // for(int i=1;i<n;i++){
        //     if(ratings[i]>ratings[i-1]){
        //         left[i]=left[i-1]+1;

        //     }else{
        //         left[i]=1;
        //     }
        // }

        // for(int i=n-2;i>=0;i--){
        //     if(ratings[i]>ratings[i+1]){
        //         right[i]=right[i+1]+1;
        //     }else{
        //         right[i]=1;
        //     }
        // }
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=max(left[i],right[i]);
        // }
        // return sum;


         int n=ratings.size();
        //  vector<int>left(n);
        //  left[0]=1;
        //  for(int i=1;i<n;i++){
        //     if(ratings[i]>ratings[i-1]){
        //         left[i]=left[i-1]+1;

        //     }else{
        //         left[i]=1;
        //     }
        // }
        // int curr=0;
        // int right=0;
        // int sum=max(left[n-1],1);
        // for(int i=n-2;i>=0;i--){
        //     if(ratings[i]>ratings[i+1]){
        //         curr=right+1;
        //         right=curr;
        //     }
        //     else{
        //         curr=1;
        //     }

        //     sum+=max(left[i],curr);
        // }
        // return sum;

        int sum=1;
        int i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum+=1;
                i++;
               continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                i++;
                down++;
            }

            if(down>peak){
                sum=sum+(down-peak);
            }
        }
        return sum;
    }
};