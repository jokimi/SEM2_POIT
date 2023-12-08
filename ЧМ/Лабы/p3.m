%F = @(x) x.^3+4.*x-2;
F = @(x) x.^2;
X = linspace(0, 1);
%plot(X,F(X))
a = 0;
b = 1;
eps = 0.01;
while ((abs(b-a) > eps) && (F(X)~=0))
    X = (a+b)/2;
    if F(X)*F(a) < 0
        b = X;
    else
        a = X;
    end
    X = (a+b)/2;
end