clear;
clc;

pkg load symbolic;

function f = showPlotsGroup(data1, data2, data3, st)
  x = data1(:, 1);
  y1 = data1(:, 2);
  y2 = data2(:, 2);
  y3 = data3(:, 2);


  figure;
  plot(x, y1, 'LineWidth', 0.3);
  hold on;
  plot(x, y2, 'LineWidth', 0.3);
  plot(x, y3, 'LineWidth', 0.3);

  xlabel('Размер массива (n)');
  ylabel('Время выполнения (в микросекундах)');
  title(st, 'FontSize', 14);
  legend('Random array', 'Reversed array', 'Almost sorted array', 'Location', 'northwest');
  grid on;
  hold off;

endfunction

function f = showPlotsBoth(data1, data2, st)
  x = data1(:, 1);
  y1 = data1(:, 2);
  y2 = data2(:, 2);

  figure;
  plot(x, y1, 'LineWidth', 0.3);
  hold on;
  plot(x, y2, 'LineWidth', 0.3);

  xlabel('Размер массива (n)');
  ylabel('Время выполнения (в микросекундах)');
  title(st, 'FontSize', 14);
  legend('QuickSort', 'IntroSort', 'Location', 'northwest');
  grid on;
  hold off;

endfunction

data1 = load('QuickSortRandom.txt');
data2 = load('IntroSortRandom.txt');
showPlotsBoth(data1, data2, 'Random array');

data1 = load('QuickSortReversed.txt');
data2 = load('IntroSortReversed.txt');
showPlotsBoth(data1, data2, 'Reversed array');

data1 = load('QuickSortAlmostSorted.txt');
data2 = load('IntroSortAlmostSorted.txt');
showPlotsBoth(data1, data2, 'Almost sorted array');


clear;
clc;

data1 = load('QuickSortRandom.txt');
data2 = load('QuickSortReversed.txt');
data3 = load('QuickSortAlmostSorted.txt');
showPlotsGroup(data1, data2, data3, 'Обычный QuickSort');

data1 = load('IntroSortRandom.txt');
data2 = load('IntroSortReversed.txt');
data3 = load('IntroSortAlmostSorted.txt');
showPlotsGroup(data1, data2, data3, 'IntroSort');



