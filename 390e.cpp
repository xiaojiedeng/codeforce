#include <iostream>
using namespace std;

struct CNode {
  int y1, y2;
  long long v;
  CNode *right;

  CNode() : y1(0), y2(0), v(0), right(NULL) {};
  CNode(int yy1, int yy2, int vv) : y1(yy1), y2(yy2), v(vv), right(NULL) {};
};

struct RNode {
  int x1, x2;
  RNode *down;
  CNode *right;

  RNode() : x1(0), x2(0), down(NULL), right(NULL) {};
  RNode(int xx1, int xx2) : x1(xx1), x2(xx2), down(NULL), right(NULL) {};
};

#define _DEBUG 1


int main() {
  int n, m, w;
  cin >> n >> m >> w;

  RNode *matrix = new RNode();
  CNode *col = new CNode(0, m, 0);
  RNode *row = new RNode(0, n);
  row->right = col;
  matrix->down = row;

#ifdef _DEBUG
  long long A[100][100] = {0};
#endif

  while (w--) {
    int e, x1, x2, y1, y2, v;
    cin >> e >> x1 >> y1 >> x2 >> y2;
    x1--; y1--;

    if (e == 0) {
      cin >> v;

#ifdef _DEBUG
      if (n < 100 && m < 100) {
        for (int i = x1; i < x2; i++)
          for (int j = y1; j < y2; j++) 
            A[i][j] += v;
      }
#endif

      for (row=matrix->down; row && row->x2<=x1; row=row->down) ;
      if (row->x1 < x1) {
        col = row->right;
        CNode *col2 = new CNode(col->y1, col->y2, col->v);

        RNode *newrow = new RNode(x1, row->x2);
        newrow->right = col2;
        row->x2 = x1;

        for (col=col->right; col; col=col->right) {
          CNode *newcol = new CNode(col->y1, col->y2, col->v);
          col2->right = newcol;
          col2 = newcol;
        }

        newrow->down = row->down;
        row->down = newrow;
        row = newrow;
      }

      for (; row && row->x2<=x2; row=row->down) {
        for (col=row->right; col && col->y2<=y1; col=col->right) ;
        if (col && col->y1 < y1) {
          CNode *newcol = new CNode(y1, col->y2, col->v);
          col->y2 = y1;
          newcol->right = col->right;
          col->right = newcol;
          col = newcol;
        }
        for (; col && col->y2<=y2; col=col->right)
          col->v += v;
        if (col && col->y1 < y2) {
          CNode *newcol = new CNode(y2, col->y2, col->v);
          col->y2 = y2;
          col->v += v;
          newcol->right = col->right;
          col->right = newcol;
        }
      }

      if (row && row->x1 < x2) {
        col = row->right;
        CNode *col2 = new CNode(col->y1, col->y2, col->v);

        RNode *newrow = new RNode(x2, row->x2);
        newrow->right = col2;
        row->x2 = x2;

        for (col=col->right; col; col=col->right) {
          CNode *newcol = new CNode(col->y1, col->y2, col->v);
          col2->right = newcol;
          col2 = newcol;
        }

        newrow->down = row->down;
        row->down = newrow;

        for (col=row->right; col && col->y2<=y1; col=col->right) ;
        if (col && col->y1 < y1) {
          CNode *newcol = new CNode(y1, col->y2, col->v);
          col->y2 = y1;
          newcol->right = col->right;
          col->right = newcol;
          col = newcol;
        }
        for (; col && col->y2<=y2; col=col->right)
          col->v += v;
        if (col && col->y1 < y2) {
          CNode *newcol = new CNode(y2, col->y2, col->v);
          col->y2 = y2;
          col->v += v;
          newcol->right = col->right;
          col->right = newcol;
        }
      }

#ifdef _DEBUG
      if (n < 100 && m < 100) {
        for (row=matrix->down; row; row=row->down)
          for (int i=row->x1; i<row->x2; i++)
            for (col=row->right; col; col=col->right)
              for (int j=col->y1; j<col->y2; j++)
                if (A[i][j] != col->v)
                  cout << "DEBUG0: (" << i << ", " << j << ") val: " << col->v << "  Exp: " << A[i][j] << endl;
      }
#endif
    }
    else {
      long long sum1 = 0;
      long long sum2 = 0;

      for (row=matrix->down; row && row->x2<=x1; row=row->down) {
        int r = row->x2 - row->x1;
        for (col=row->right; col && col->y2<=y1; col=col->right) {
          int c = col->y2 - col->y1;
          sum1 += r*c*col->v;
        }
        if (col && col->y1<y1) {
          int c = y1 - col->y1;
          sum1 += r*c*col->v;
        }
        for (; col && col->y2<=y2; col=col->right) ;
        for (; col; col=col->right) {
          int c = col->y2 - max(col->y1, y2);
          sum1 += r*c*col->v;
        }
      } 
      if (row && row->x1<x1) {
        int r = x1 - row->x1;
        for (col=row->right; col && col->y2<=y1; col=col->right) {
          int c = col->y2 - col->y1;
          sum1 += r*c*col->v;
        }
        if (col && col->y1<y1) {
          int c = y1 - col->y1;
          sum1 += r*c*col->v;
        }
        for (; col && col->y2<=y2; col=col->right) ;
        for (; col; col=col->right) {
          int c = col->y2 - max(col->y1, y2);
          sum1 += r*c*col->v;
        }
      }

      for (; row && row->x2<=x2; row=row->down) {
        int r = row->x2 - max(row->x1, x1);
        for (col=row->right; col && col->y2<=y1; col=col->right) ;
        for (; col && col->y1<y2; col=col->right) {
          int c = min(col->y2, y2) - max(col->y1, y1);
          sum2 += r*c*col->v;
        }
      }
      if (row && row->x1<x2) {
        int r = x2 - max(row->x1, x1);
        for (col=row->right; col && col->y2<=y1; col=col->right) ;
        for (; col && col->y1<y2; col=col->right) {
          int c = min(col->y2, y2) - max(col->y1, y1);
          sum2 += r*c*col->v;
        }
      }

      for (; row; row=row->down) {
        int r = row->x2 - max(row->x1, x2);
        for (col=row->right; col && col->y2<=y1; col=col->right) {
          int c = col->y2 - col->y1;
          sum1 += r*c*col->v;
        }
        if (col && col->y1<y1) {
          int c = y1 - col->y1;
          sum1 += r*c*col->v;
        }
        for (; col && col->y2<=y2; col=col->right) ;
        for (; col; col=col->right) {
          int c = col->y2 - max(col->y1, y2);
          sum1 += r*c*col->v;
        }
      }

#ifdef _DEBUG
      if (n < 100 && m < 100) {
        long long s1, s2, s3;
        s1 = s2 = s3 = 0;
        for (int i=0; i<x1; i++) {
          for (int j=0; j<y1; j++)
            s1 += A[i][j];
          for (int j=y2; j<m; j++)
            s1 += A[i][j];
        }

        for (int i=x1; i<x2; i++)
         for (int j=y1; j<y2; j++)
          s2 += A[i][j];

        for (int i=x2; i<n; i++) {
          for (int j=0; j<y1; j++)
            s3 += A[i][j];
          for (int j=y2; j<m; j++)
            s3 += A[i][j];
        }

        if (sum2 != s2)
          cout << "DEBUG1: sum2 (" << sum2 << ") != s2 (" << s2 << ")" << endl;
        if (sum1 != s1+s3)
          cout << "DEBUG1: sum1 (" << sum1 << ") != s1 (" << s1 << ") + s3 (" << s3 << ")" << endl;
      }
#endif


      cout << sum2-sum1 << endl;
    }
  }

  return 0;
}
