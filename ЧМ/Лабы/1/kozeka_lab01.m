f1 = @(x) ((asin(7 .* x)).^2 + 1) ./ sqrt(1 - 49 .* x.^2);
f2 = @(x) 1 ./ log(4 .* x + 1.1);

a = 1;
b = 0.1;
n1 = 10;
n2 = 100;

int1 = integral(f1, a, b);
int2 = integral(f2, a, b);

disp('Метод прямоугольников:');
ansRect1_1 = rectangle(f1, a, b, n1);
ansRect1_2 = rectangle(f1, a, b, n2);
ansRect2_1 = rectangle(f2, a, b, n1);
ansRect2_2 = rectangle(f2, a, b, n2);

disp('Метод трапеций:');
ansTrap1_1 = trapezoid(f1, a, b, n1);
ansTrap1_2 = trapezoid(f1, a, b, n2);
ansTrap2_1 = trapezoid(f2, a, b, n1);
ansTrap2_2 = trapezoid(f2, a, b, n2);

disp('Метод Симпсона:');
ansSimp1_1 = simpson(f1, a, b, n1);
ansSimp1_2 = simpson(f1, a, b, n2);
ansSimp2_1 = simpson(f2, a, b, n1);
ansSimp2_2 = simpson(f2, a, b, n2);

disp('Погрешности для первого интеграла:');
disp(' ');
disp('Относительные:');
disp(' ');
disp('Погрешность методом прямоугольников:');
relerrorRect1_1 = relerrors(int1, ansRect1_1);
relerrorRect1_2 = relerrors(int1, ansRect1_2);
disp('Погрешность методом трапеций:');
relerrorTrap1_1 = relerrors(int1, ansTrap1_1);
relerrorTrap1_2 = relerrors(int1, ansTrap1_2);
disp('Погрешность методом Cимпсона:');
relerrorSimp1_1 = relerrors(int1, ansSimp1_1);
relerrorSimp1_2 = relerrors(int1, ansSimp1_2);

disp('Абсолютные:');
disp(' ');
disp('Погрешность методом прямоугольников:');
abserrorRect1_1 = abserrors(int1, ansRect1_1);
abserrorRect1_2 = abserrors(int1, ansRect1_2);
disp('Погрешность методом трапеций:');
abserrorTrap1_1 = abserrors(int1, ansTrap1_1);
abserrorTrap1_2 = abserrors(int1, ansTrap1_2);
disp('Погрешность методом Cимпсона:');
abserrorSimp1_1 = abserrors(int1, ansSimp1_1);
abserrorSimp1_2 = abserrors(int1, ansSimp1_2);

disp('Погрешности для второго интеграла:');
disp(' ');
disp('Относительные:');
disp(' ');
disp('Погрешность методом прямоугольников:');
relerrorRect2_1 = relerrors(int2, ansRect2_1);
relerrorRect2_2 = relerrors(int2, ansRect2_2);
disp('Погрешность методом трапеций:');
relerrorTrap2_1 = relerrors(int2, ansTrap2_1);
relerrorTrap2_2 = relerrors(int2, ansTrap2_2);
disp('Погрешность методом Cимпсона:');
relerrorSimp2_1 = relerrors(int2, ansSimp2_1);
relerrorSimp2_2 = relerrors(int2, ansSimp2_2);

disp('Абсолютные:');
disp(' ');
disp('Погрешность методом прямоугольников:');
abserrorRect2_1 = abserrors(int2, ansRect2_1);
abserrorRect2_2 = abserrors(int2, ansRect2_2);
disp('Погрешность методом трапеций:');
abserrorTrap2_1 = abserrors(int2, ansTrap2_1);
abserrorTrap2_2 = abserrors(int2, ansTrap2_2);
disp('Погрешность методом Cимпсона:');
abserrorSimp2_1 = abserrors(int2, ansSimp2_1);
abserrorSimp2_2 = abserrors(int2, ansSimp2_2);

function ansRect = rectangle(f, a, b, n)
ansRect = 0;
h = (b-a) / n;
temp = a + h./2;
for i=temp:h:b
    ansRect = ansRect + f(i);
end
ansRect = ansRect .* h;
disp(ansRect);
end

function ansTrap = trapezoid(f, a, b, n)
ansTrap = 0;
h = (b-a) / n;
for i=a:h:b
    if i~=b
        ansTrap = ansTrap + (f(i)+f(i+h))/2*h;
    end
end
disp(ansTrap);
end

function ansSimp = simpson(f, a, b, n)
ansSimp = 0;
h = (b-a) / n;
k = 1;
x = a:h:b;
while k <= n+1
    if (k ~= 1) && (k ~= n+1) && (mod(k, 2) == 0)
        ansSimp = 4 .* f(x(k)) + ansSimp;
    elseif (k ~= 1) && (k ~= n+1) && (mod(k, 2) ~= 0)
        ansSimp = 2 .* f(x(k)) + ansSimp;
    else
        ansSimp = f(x(k)) + ansSimp;
    end
    k = k + 1;
end
ansSimp = h ./ 3 .* ansSimp;
disp(ansSimp);
end

function error = relerrors(int, answer)
error = (int - answer) ./ int .* 100;
disp(abs(error));
end

function error = abserrors(int, answer)
error = (int - answer) ./ int;
disp(abs(error));
end