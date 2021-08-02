/*
First observation we should make to be able to solve this problem: 
if two matrices have common subsquare of size X, they also have common subsquares
 of sizes X-1, X-2, X-3,... ,1 (you may simply take part of large subsquare).
This observation should make idea of using binary search here quite obvious. 
Now we need to learn how to check that given matrices have common subsquare of size X.
Quite a few of tests are small&random enough to give you points even for some naive checking - running 
over all squares in first matrix, comparing them with all squares in second matrix (you may add some smart breaks here etc.).
 However, this isn't supposed to give you a full score.
First improvement is to learn how to compare two squares faster than with naive checking. Here hashing can help us.

Hashing will allow us to represent whole square as a single number, and compare two squares by comparing corresponding numbers.
Type "Rabin-Karp 2d" in Google and at the first page you'll have several different guides/implementations for 2d version of 
Rabin-Karp algorithm. If you are completely new to all these things - start with 1d version of algorithm 
(where we are comparing substrings instead of subsquares). After understanding 1d version - 2d version should be also 
pretty clear, because it is a simple generalization of 1d.

Now we have O(N^4) checker for particular value of X, which is still too slow (but much better than before).
How to improve it even more? Instead of comparing our subsquare with every single subsquare from other matrix, 
we may compare it with all subsquares from that matrix at the same time. We are interested to know if there is 
a pair of equal subsquares; let's put all subsquares of first matrix in a set. Now for every subsquare from second 
matrix we can check if it has a pair in first matrix, by simply looking at our set. It gives us logN instead of N^2 here.
Now we have some sort of proper solution. Time limit isn't very strict; however, if you are actually going to use sets, 
it may be too slow. Instead you may store all values in sorted vector and use std::lower_bound() to check that 
some value is presented there. Also you may get rid of any % operations by doing all calculations modulo 2^64 
(yes, there were no anti-hash tests in data set :) ) Such solution should get full score without any problems.
 
*/
 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class problem3 {

    /**
     * @param args
     */
    static int[][] matrix1;
    static int[][] matrix2;
    static int comparison = 0;

    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        String[] parts = input.split(" ");
        int n = Integer.parseInt(parts[0]);
        int m = Integer.parseInt(parts[1]);
        matrix1 = new int[n][m];
        for (int i = 0; i < n; i++) {
            input = br.readLine();
            parts = input.split(" ");
            for (int j = 0; j < m; j++) {
                matrix1[i][j] = Integer.parseInt(parts[j]);
            }
        }
        input = br.readLine();
        parts = input.split(" ");
        int x = Integer.parseInt(parts[0]);
        int y = Integer.parseInt(parts[1]);
        matrix2 = new int[x][y];
        for (int i = 0; i < x; i++) {
            input = br.readLine();
            parts = input.split(" ");
            for (int j = 0; j < y; j++) {
                matrix2[i][j] = Integer.parseInt(parts[j]);
            }
        }
        int min = m;
        if (n < m) {
            min = n;
        }
        if (x < min) {
            min = x;
        }
        if (y < min) {
            min = y;
        }
//        boolean ansSet = false;
//        for (int i = min; i > 0; i--) {
//            if (CompareAllSquaresOfGivenSize(i, n, m, x, y)) {
//                System.out.println(i);
//                ansSet = true;
//                break;
//            }
//        }
//        if (!ansSet)
//            System.out.println(0);
       
        System.out.println(Calc(0,min,n,m,x,y,min));
    }

    public static int Calc(int start,int end,int n,int m, int x, int y,int maxSquareSide)
    {
        if(start==0 && end==0)
        {
            return 0;
        }
            int mid=(start+end)/2;
            if(CompareAllSquaresOfGivenSize(mid, n,m,x,y))
            {
                if(!CompareAllSquaresOfGivenSize(mid+1, n,m,x,y))
                {
                    return mid;
                }
                if(mid+1<=maxSquareSide)
                    return Calc(mid+1,end,n,m,x,y,maxSquareSide);
                else
                    return mid;
            }
            else
            {
                return Calc(start,mid-1,n,m,x,y,maxSquareSide);
            }
   
    }

    public static boolean CompareAllSquaresOfGivenSize(int size, int n, int m,
            int x, int y) {
        for (int startingPointRow1 = 0; startingPointRow1 + size - 1 < n; startingPointRow1++) {
            for (int startingPointColum1 = 0; startingPointColum1 + size - 1 < m; startingPointColum1++) {
                for (int startingPointRow2 = 0; startingPointRow2 + size - 1 < x; startingPointRow2++) {
                    for (int startingPointColum2 = 0; startingPointColum2
                            + size - 1 < y; startingPointColum2++) {
                        // System.out.println("matrix1row: "+startingPointRow1 +
                        // " matrix1Col: " + startingPointColum1 +
                        // " matrix2row: "+startingPointRow2 +
                        // " matrix2Col: " + startingPointColum2
                        // + " size: "+size);
                        if (compareSquares(startingPointRow1,
                                startingPointColum1, startingPointRow2,
                                startingPointColum2, size))
                            return true;
                    }
                }
            }
        }
        return false;
    }

    public static boolean compareSquares(int square1Row, int square1Column,
            int square2Row, int square2Column, int SquareLength) {
        comparison++;
        for (int i = 0; i < SquareLength; i++) {
            for (int j = 0; j < SquareLength; j++) {
                if (matrix1[square1Row + i][square1Column + j] != matrix2[square2Row
                        + i][square2Column + j]) {
                    return false;
                }
            }
        }
        return true;
    }

}