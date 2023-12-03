#include <iostream>

void recursionPath(unsigned long long& res, unsigned long long& iterations, int posX, int posY, int finX, int finY){
    iterations += 1;
    if((posX == finX) && (posY == finY)){
        res += 1;
    }
    if(posX < finX){
        recursionPath(res, iterations, posX+1, posY, finX, finY);
    }
    if(posY < finY){
        recursionPath(res, iterations, posX, posY+1, finX, finY);
    }
}

int main(){
    int n;
    int m;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter m: ";
    std::cin >> m;

    unsigned long long res = 0;
    unsigned long long iterations = 0;
    recursionPath(res, iterations, 0, 0, n-1, m-1);
    std:: cout << "Number of paths: "<< res << " Number of recursions: " << iterations << std::endl;

    unsigned long long ** grid = new unsigned long long *[m];
    for(int i = 0; i < m; i++){
        grid[i] = new unsigned long long [n];
    }
    grid[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i > 0){
                grid[i][j] += grid[i-1][j];
            }
            if(j > 0){
                grid[i][j] += grid[i][j-1];
            }
        }
    }
    std:: cout << "Number of paths: "<< grid[n-1][m-1] << " Number of iterations: " << (n*m) << std::endl;
    for(int i = 0; i < m; i++){
        delete [] grid[i];
    }
    delete [] grid;
    return 0;
}
