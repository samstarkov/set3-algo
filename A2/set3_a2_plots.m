clear;
clc;

pkg load symbolic;

function f = showPlotsMS(data, st)
  x = data(:, 1);
  y = data(:, 2);

  figure;
  plot(x, y, 'LineWidth', 0.5);
  hold on;

  xlabel('Размер массива (n)');
  ylabel('Время выполнения (в микросекундах)');
  legend(st);
  title('Обычный MergeSort', 'FontSize', 14);
  grid on;
  hold off;

endfunction

function f = showPlotsHMS(data, st)
  x = data(:, 1);
  y1 = data(:, 2);
  y2 = data(:, 3);
  y3 = data(:, 4);
  y4 = data(:, 5);
  y5 = data(:, 6);


  figure;
  plot(x, y1, 'LineWidth', 0.3);
  hold on;
  plot(x, y2, 'LineWidth', 0.3);
  plot(x, y3, 'LineWidth', 0.3);
  plot(x, y4, 'LineWidth', 0.3);
  plot(x, y5, 'LineWidth', 0.3);

  xlabel('Размер массива (n)');
  ylabel('Время выполнения (в микросекундах)');
  title(st, 'FontSize', 14);
  legend('th = 5', 'th = 10', 'th = 20', 'th = 30', 'th = 50', 'Location', 'northwest');
  grid on;
  hold off;

endfunction

function f = showPlotsBoth(dataMS, dataHMS, st)
  x = dataMS(:, 1);
  y1 = dataMS(:, 2);
  y2 = dataHMS(:, 1);


  figure;
  plot(x, y1, 'LineWidth', 0.3);
  hold on;
  plot(x, y2, 'LineWidth', 0.3);

  xlabel('Размер массива (n)');
  ylabel('Время выполнения (в микросекундах)');
  title(st, 'FontSize', 14);
  legend('MergeSort', 'HybridMergeSort (th = 30)', 'Location', 'northwest');
  grid on;
  hold off;

endfunction

data1 = load('HybridMergeSortRandom.txt');
showPlotsHMS(data1, 'HybridMergeSort с различными threshold (random array)');
data2 = data1(:, 5);
data1 = load('MergeSortRandom.txt');
showPlotsMS(data1, 'Random array');
showPlotsBoth(data1, data2, 'Random array');

data1 = load('HybridMergeSortReversed.txt');
showPlotsHMS(data1, 'HybridMergeSort с различными threshold (reversed array)');
data2 = data1(:, 5);
data1 = load('MergeSortReversed.txt');
showPlotsMS(data1, 'Reversed array');
showPlotsBoth(data1, data2, 'Reversed array');

data1 = load('HybridMergeSortAlmostSorted.txt');
showPlotsHMS(data1, 'HybridMergeSort с различными threshold (almost sorted array)');
data2 = data1(:, 5);
data1 = load('MergeSortAlmostSorted.txt');
showPlotsMS(data1, 'Almost sorted array');
showPlotsBoth(data1, data2, 'Almost sorted array');



