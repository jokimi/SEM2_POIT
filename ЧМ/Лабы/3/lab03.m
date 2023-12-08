F = @(x) x.^3+5.*x-4;
X = -10:1:10;
plot(X,F(X));
a = -2;
b = 2;
eps = 0.01; %допустимая погрешность
[der1, der2] = derivative(); %находим производную
ans1 = first(F,a,b,eps);
ans2 = second(F,a,b,eps,der1,der2);
ans3 = third(F,a,eps,der1);
%Метод деления отрезка пополам
function answer = first(F,a,b,eps)
    while abs(b-a) > eps  %пока больше допустимой погрешности 
        answer = (a+b)/2;
        if F(a)*F(answer) < 0 %если принимает значения разных знаков, то b будет принят как интервал 
            b = answer;
        elseif F(b)*F(answer) < 0
            a = answer;
        end     
    end
    answer = (a+b)/2;
end
%Метод Ньютона (метод касательных)
function answer = second(F,a,b,eps, der1,der2) 
    if F(a)*der2(a) > 0 %если верно, то за начальное приближение будет принят конец отрезка на a
            answer = a;
    elseif F(b)*der2(b) > 0
            answer = b;
    end     
    pr = F(answer)/der1(answer); %за следующее приближение
    while abs(pr) > eps
        pr = F(answer)/der1(answer);
        answer = answer - pr;
    end
end
%Метод простой итерации
function answer = third(F,a,eps,der1)
    M = @(a) 1.01.*der1(a); %Неизвестная постоянная величина, которая определяется из условия сходимости метода простой итерации
    k = M(a);
    f = @(answer) answer-F(answer)./k; %приводит к функции для дальнейшего использования
    answer = a;
    pr = 1;
    while pr > eps %прекращается, если результаты двух последних итераций близки 
       answer = a;
       a = f(answer);
       pr = abs(a - answer);
    end
end
%производная
function [der1,der2] = derivative()
    syms x;
    f = x.^3+5.*x-4;
    der1 = matlabFunction(diff(f));
    der2 = matlabFunction(diff(f, 2));  
end