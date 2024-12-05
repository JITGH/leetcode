class Solution {
public:
    bool canChange(string start, string target) {


        // USING QUEUE->O(n)
        //TAKE Two queue to store the L & R with their pos int start and target
        //then check whether its same size and if not return false; because not contain same no of L and R in queue
        //if its same size then check if their charaecter it in position with 
        //if its L then whether its left to the target queue L pos OR
        //if its R then whether its right to the target queue R pos then it gives false;
        //either true;
//         queue<pair<char,int>>sq,tq;
//         for(int i=0;i<start.size();i++){
//             if(start[i]!='_'){
//                 sq.push({start[i],i});
//             }
//         }

//         for(int i=0;i<target.size();i++){
//             if(target[i]!='_'){
//                 tq.push({target[i],i});
//             }
//         }

//         if(sq.size()!=tq.size()) return false;
//         while(!sq.empty()){
//             auto it=sq.front();
//             sq.pop();
//             auto ti=tq.front();
//             tq.pop();
// //check if character match and movement rule
//             if(it.first!=ti.first||(it.first=='L' && it.second<ti.second)||
//             (it.first=='R' && it.second>ti.second)){
//                 return false;
//             }
//         }
//         return true;



//  TWO POINTER -> O(N)

          int startLength = start.size();
        // Pointer for start string and target string
        int startIndex = 0, targetIndex = 0;

        while (startIndex < startLength || targetIndex < startLength) {
            // Skip underscores in start
            while (startIndex < startLength && start[startIndex] == '_') {
                startIndex++;
            }
            // Skip underscores in target
            while (targetIndex < startLength && target[targetIndex] == '_') {
                targetIndex++;
            }
            // If one string is exhausted, both should be exhausted
            if (startIndex == startLength || targetIndex == startLength) {
                return startIndex == startLength && targetIndex == startLength;
            }

            // Check if the pieces match and follow movement rules
            if (start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex))
                return false;

            startIndex++;
            targetIndex++;
        }

        // If all conditions are satisfied, return true
        return true;
         
    }
};