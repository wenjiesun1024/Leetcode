class Solution {
public:
   int getSum(int a, int b) {
       while (b != 0) { 
           int carry = a & b;
           a = a ^ b;
           b = (carry & 0x7fffffff) << 1; //������������
       }
       return a;
   }  
};