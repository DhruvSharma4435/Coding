class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int row = 1;
        if(red <= 1 && blue <= 1)
           return row;
        //start from red
        
        int  redBall = 0, blueBall = 0;
        bool flag = true;
        while(redBall <= red && blueBall <= blue)
        {
            if(flag)
            {
                redBall += row; 
                if(redBall > red)
                  break;
                row++;
                flag = false;
            }
            else
            {
                blueBall += row;
                if(blueBall > blue)
                  break;
                row++;
                flag = true;
            }
        }
        int maxi = row- 1;
        row = 1;
        redBall = 0, blueBall = 0;
        flag = true;
        while(redBall <= red && blueBall <= blue)
        {
            if(flag)
            {
                blueBall += row;
                if(blueBall > blue)
                  break; 
                row++;
                flag = false;
            }
            else
            {
                redBall += row;
                if(redBall > red)
                   break; 
                row++;
                flag = true;
            }
        }
        return max(maxi, row-1);

    }
};