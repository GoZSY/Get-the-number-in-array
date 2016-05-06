/************************************************************
* 矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，

* 因此从左下角开始查找，当要查找数字比左下角数字大时。右移

* 要查找数字比左下角数字小时，上移
递归实现
*************************************************************/
class Solution {
public:
    bool Find(vector<vector<int> > array,int target) 
    {
    	int lengthx = array.size();
        if(lengthx == 0)
            return false;
        int lengthy = array[0].size();
        int row = lengthx;
        int rows = 0;
        int cols = lengthy-1;
        return Find(array,target,row,rows,cols);
    }
    
private:
    bool Find(vector<vector<int> > &array,int target,int row, int &rows,int &cols)
    {
        if(rows < 0 || cols < 0 || rows >= row)
            return false;
        if(array[rows][cols] == target)
            return true;
        if(array[rows][cols] > target)
            cols --;
        if(array[rows][cols] < target)
            rows ++;
        return Find(array,target,row,rows,cols);
    }
};

/************************************************
循环实现
**************************************************/
class Solution
{
public:
    bool Find(vector<vector<int> > array,int target)
    {
        bool found = false;
        if(static_cast <int> (array.size())>0)
            {
            int rows = array.size();
            int columns = array[0].size();
            int row = 0;
            int column = columns - 1;
            while(row < rows && column >= 0)
                {
                 if(array[row][column] == target)
                 {
                     found = true;
                      break;   
                 }     
                 else if(array[row][column] > target)
                     --column;
                 else      
                     ++ row;
                }
            }
        return found;
    }
};
