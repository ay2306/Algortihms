data = load('Data.txt');
X = data(:,2);
Y = data(:,1);
xlabel("Iterations");
ylabel("Cost Function");
scatter(X,Y);
hold on
