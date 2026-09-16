class Solution {
public:
    vector<vector<char>>ans;

    bool checkrow(char num,int row,vector<vector<char>>&board) {
        for(int j=0;j<9;j++) if(board[row][j]==num) return 0;
        return 1;
    }

    bool checkcol(char num,int col,vector<vector<char>>&board) {
        for(int i=0;i<9;i++) if(board[i][col]==num) return 0;
        return 1;
    }

    bool checkgrid(char num,int row,int col,vector<vector<char>>&board) {
        int r=6,c=6;
        if(row<3) r=0;
        else if(row<6) r=3;
        if(col<3) c=0;
        else if(col<6) c=3;
        for(int i=r;i<r+3;i++) {
            for(int j=c;j<c+3;j++) if(board[i][j]==num) return 0;
        }
        return 1;
    }

    void makemove(vector<vector<char>>& board,int i,int j) {
        if(i==9) {
            ans=board;
            return;
        }
        if(j==9) makemove(board,i+1,0);
        else if(board[i][j]!='.') makemove(board,i,j+1);
        else {
            for(int k=1;k<=9;k++) {
                if(checkrow(k+'0',i,board)==1 && checkcol(k+'0',j,board)==1 && checkgrid(k+'0',i,j,board)==1) {
                    board[i][j]=k+'0';
                    makemove(board,i,j+1);
                    board[i][j]='.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        makemove(board,0,0);
        board = ans;
    }
};