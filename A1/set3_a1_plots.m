clear;
clc;

pkg load symbolic;

function f = showPlots(data, answer)
  x = data(:, 1);
  y1 = data(:, 2);
  y2 = data(:, 3);

  ans_arr = answer * ones(200, 1);

  figure('Name', 'Зависимость приближенной площади от количества точек', 'numbertitle', 'off');
  plot(x, ans_arr, 'black', 'LineWidth', 0.3);
  hold on;
  plot(x, y1, 'LineWidth', 0.5);
  plot(x, y2, 'LineWidth', 0.5);
  hold off;

  xlabel('n');
  ylabel('ans');
  title('Зависимость приближенной площади от количества точек', 'FontSize', 14);
  legend('Ответ', 'Использование большой зоны', 'Использование маленькой зоны');
  grid on;


  deviation_y1 = abs((y1 - answer) / answer) * 100;
  deviation_y2 = abs((y2 - answer) / answer) * 100;

  figure('Name', 'Процентное отклонение (линейная шкала)', 'numbertitle', 'off');

  plot(x, deviation_y1, 'LineWidth', 0.5);
  hold on;
  plot(x, deviation_y2, 'LineWidth', 0.5);
  hold off;

  xlabel('n');
  ylabel('Отклонение, %');
  title('Процентное отклонение приближенной площади от точного ответа', 'FontSize', 14);
  legend('Отклонение для большой зоны', 'Отклонение для маленькой зоны');
  grid on;
endfunction

data1 = load('resultData1.txt');
data2 = load('resultData2.txt');
showPlots(data1, 0.44380799999999998029);
showPlots(data2, 2.01463200000000020040);


