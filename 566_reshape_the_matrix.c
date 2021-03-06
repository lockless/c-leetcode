/* 在Matlab中有一个非常有用的函数叫 reshape，他可以将矩阵重新组成一个不同的大小，但是不改变其原始数据
 给出一个由二维数组表示的矩阵，两个正整数r和c分别表示所需重组矩阵的行号和列号。
 重新组合的矩阵需要以与它们相同的行遍历顺序填充原始矩阵的所有元素。
 如果具有给定参数的“重塑”操作是可行且合法的，则输出新的重构矩阵; 否则，输出原始矩阵。


	例1:
	输入:  nums = [[1,2],
				   [3,4]]
		   r = 1, 
		   c = 4

	输出: [[1,2,3,4]]
	解释: 数字的行遍历是[1,2,3,4]。 新的重构矩阵是一个1 * 4矩阵，使用上一个列表逐行填充。

	
	例2:
	输入:  nums = [[1,2],
				   [3,4]]
		   r = 2, 
		   c = 4
	输出: [[1,2],
		   [3,4]]
	解释: 无法重塑，输出原来的数组
*/

int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
    if (r * c != numsRowSize * numsColSize) {
        r = numsRowSize;
        c = numsColSize;
    }

    *returnSize = r;
    int** result = (int**) malloc(r * sizeof(int*));
    *columnSizes = (int*) malloc(r * sizeof(int));
    for (int i = 0; i < r; ++i) {
        result[i] = (int*) malloc(c * sizeof(int));
        (*columnSizes)[i] = c;
    }
    
    for (int i = 0; i < numsRowSize * numsColSize; ++i)
        result[i/c][i%c] = nums[i/numsColSize][i%numsColSize];

    return result;  
}