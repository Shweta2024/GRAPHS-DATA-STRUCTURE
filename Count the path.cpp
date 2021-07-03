//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

//Checker function to see if the alloted color is safe
bool isSafe(int u,int col,bool graph[101][101],vector<int>color,int m,int V)
{
    for(int i=0;i<V;i++) //iterate through all the node
    {
        if(i!=u && graph[i][u]==1 && color[i]==col) //consitions to be checked
        return false;
    }
    return true;
}

//Function to allote color and recursively color for all the nodes
bool dfs(bool graph[101][101],vector<int>color,int u,int m,int V)
{
    if(u==V) //Base Case:Once the last node is colored,return true
    return true;
    for(int i=1;i<=m;i++) //iterating through all the colors
    {
        color[u]=i; //Assign color to the  current node
    if(isSafe(u,i,graph,color,m,V)) //Check if the alloted color is Safe or not
    {
        bool flag=dfs(graph,color,u+1,m,V); //Make a recursive call if the alloted color is safe
        if(flag)
        return true;
    }
    }
    color[u]=0; //undo the color
    return false; //if the nodes cant be colored from the available options,return false
}
//Algorithm
/*
Concept of Backtracking is used
1.Color each vertex ensuring thst it's safe to color with the current color,otherwise try other color
2.Once the last node have been colored return true(Base Case)
*/
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int>color(V,0); //to keep track of the colors of nodes,initially all are 0
    if(dfs(graph,color,0,m,V)) //make a dfs call
    return true;
    else
    return false;
}