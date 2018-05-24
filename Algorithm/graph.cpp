#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

enum class GraphKind
{
    DG,
    DN,
    UDG,
    UDN
};

// T denote vertex type
// InfoType denote information type it hold.
template <typename T, typename InfoType>
struct ArcCell
{
    T adj;
    
    InfoType info;
};

template <typename T, typename InfoType>
using AdjMatrix = ArcCell<T, InfoType>[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

template <typename T>
class MatrixGraph
{
public:
    MatrixGraph() = default;

    bool CreateGraph()
    {
        cout << "输入graph类型:" << endl;
        int i;
        cin >> i;
        switch (i)
        {
            case /*GraphKind::DG*/1:
                return CreateDG();
                break;
            case /*GraphKind::*/2:
                return CreateDN();
                break;
            case 3:
                return CreateUDG();
                break;
            case 4:
                return CreateUDN();
                break;
            default:
                return false;
        }// switch
    }// CreateGraph

    void Print()
    {
        cout << "vertex:" << endl;
        for (int i = 0; i < vertexs_num_; ++i)
        {
            cout << vertexs_[i] << " ";
        }// for
        cout << endl;
        cout << "arcs:" << endl;
        for (int i = 0; i < vertexs_num_; ++i)
        {
            for (int j = 0; j < vertexs_num_; ++j)
            {
                cout << arcs_[i][j].adj << "  ";
            }// for
            cout << endl;
            cout << endl;
        }// for
    }// Print

private:
    bool CreateDG()
    {
        return true;
    }

    bool CreateDN()
    {
        return true;
    }

    bool CreateUDG()
    {
        return true;
    }

    bool CreateUDN()
    {
        cout << "输入顶点、弧数量:";
        cin >> vertexs_num_
            >> arcs_num_;
        cout << "input vex data:" << endl;
        // vex data
        for (int i = 0; i < vertexs_num_; ++i)
        {
            cin >> vertexs_[i];
        }
        // init adjacent matrix
        for (int i = 0; i < vertexs_num_; ++i)
        {
            for (int j = 0; j < vertexs_num_; ++j)
            {
                arcs_[i][j].adj = ".";
                arcs_[i][j].info = "default";
            }// for
        }// for
        // construct adjacent matrix
        for (int k = 0; k < arcs_num_; ++k)
        {
            cout << "输入弧，前、后结点和权:" << endl;
            T v1;
            T v2;
            string weight;
            cin >> v1
                >> v2
                >> weight;
            int i = LoacateVex(v1);
            int j = LoacateVex(v2);
            arcs_[i][j].adj = weight;
            arcs_[j][i] = arcs_[i][j];
        }// for
        return true;
    }

    // the first value
    int LoacateVex(T v)
    {
        for (int i = 0; i < vertexs_num_; ++i)
        {
            if (v == vertexs_[i])
            {
                return i;
            }
        }// for
        // not found
        return -1;
    }

private:
    // vertex data
    T vertexs_[MAX_VERTEX_NUM];
    AdjMatrix<string, string> arcs_;
    int vertexs_num_;
    int arcs_num_;
};

int main()
{
    MatrixGraph<string> mg;
    mg.CreateGraph();
    mg.Print();
    return 0;
}