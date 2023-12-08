%Метод Гаусса
A = [3 2 0 -1; 2 1 3 -1; 1 2 5 -1; 2 2 5 -1];
B = [2; 1; 0; 1];
proverka=det(A);
if(proverka ~= 0 && A(1,1) ~= 0)
    [numRows, numCols] = size(A);
    matrix = [ A B];
    disp(matrix);
    i = 2;
    m = 2;
    j = 1;
    while i < 5
        if matrix(i,i) ~= 0
            for i=i:1:numRows
                matrix(i,:) = matrix(i,:)- matrix(j,:)/matrix(j,j)*matrix(i,j);
            end
        end
        m = m + 1;
        i = m;
        j = j + 1;
    end
    disp(matrix);
    disp('Решение'); 
    x(4) = matrix(4,5)/matrix(4,4);
    x(3) = matrix(3,5) - matrix(3,4) * x(4);
    x(2) = matrix(2,5) - matrix(2,4) * x(4) - matrix(2,3) * x(3);
    x(1) = matrix(1,5) - matrix(1,4) * x(4) - matrix(1,3) * x(3) - matrix(1,2) * x(2);
    X = [x(1), x(2), x(3), x(4)];

    A_1 = [3 2 0 -1; 2 1 3 -1; 1 2 5 -1; 2 2 5 -1];
    B_1 = [2; 1; 0; 1];
    X_1 = inv(A_1)*B_1;
end