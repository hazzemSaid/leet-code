function maxMatrixSum(matrix: number[][]): number {
    let minn = 1e9;
    let sum = 0;
    let cnt = 0;
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            if (matrix[i][j] < 0) cnt++;
            minn = Math.min(minn, Math.abs(matrix[i][j]));
            sum += Math.abs(matrix[i][j]);
        }
    }
    if (cnt % 2 == 0) return sum;
    return sum - (minn * 2);
};