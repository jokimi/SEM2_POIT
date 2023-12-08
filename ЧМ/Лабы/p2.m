x = [-2, -5, -7, -8, -11, -12, -17, -18];
y = [0.3, 0.7, 1.3, 1.4, 1.9, 2, 3.1, 4];
% plot(x, y);
n = size(x, 2);
A = [n, sum(x); sum(x), sum(x .^ 2)];
a = inv(A) * [sum(y); sum(x .* y)];
f = @(x) a(1) + a(2) .* x;
plot(x, f(x), x, y);