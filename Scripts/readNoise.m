fileID = fopen('byteArrayX.bin');
input = fread(fileID, 'float');
fclose(fileID);

fileID = fopen('resultY.bin');
output = fread(fileID, 'float');
fclose(fileID);


d = length(output) / 3;    % Separate_reading_signals
output1 = output(1 : d);
output2 = output(d + 1 : 2 * d);
output3 = output(2 * d + 1 : end);

j = length(input) / 3;    % Separate_reading_signals
input1 = input(1 : j);
input2 = input(j + 1 : 2 * j);
input3 = input(2 * j + 1 : end);



itterColum = 1;
itterVolume = 2;

y1ReIm = zeros(10000, 1);
y2ReIm = zeros(10000, 1);
y3ReIm = zeros(10000, 1);

x1ReIm = zeros(10000, 1);
x2ReIm = zeros(10000, 1);
x3ReIm = zeros(10000, 1);


for k = 1 : 10000
 
y1ReIm(k, 1) = output1(itterColum, 1) + output1(itterVolume, 1) * 1i;
y2ReIm(k, 1) = output2(itterColum, 1) + output2(itterVolume, 1) * 1i;
y3ReIm(k, 1) = output3(itterColum, 1) + output3(itterVolume, 1) * 1i;

x1ReIm(k, 1) = input1(itterColum, 1) + input1(itterVolume, 1);
x2ReIm(k, 1) = input2(itterColum, 1) + input2(itterVolume, 1);
x3ReIm(k, 1) = input3(itterColum, 1) + input3(itterVolume, 1);

  
itterColum = itterColum + 2;
itterVolume = itterVolume + 2;   
    
end

%[pxx1,f1] = pwelch(y1ReIm, [], [], 256, 3, 'centerdc', 'power');
%plot(f1, pow2db(pxx1));
%hold on

%[pxx2, f2] =pwelch(y2ReIm, [], [], 256, 3, 'centerdc', 'power');
%plot(f2, pow2db(pxx2));
%hold on
%[pxx3, f3] = pwelch(y3ReIm, [], [], 256, 3, 'centerdc', 'power');
%plot(f3, pow2db(pxx3));
hold on
[pxx4, f4] = pwelch(x1ReIm, [], [], 256, 3, 'centerdc', 'power');
plot(f4, pow2db(pxx4));
hold on
[pxx5, f5] = pwelch(x2ReIm, [], [], 256, 3, 'centerdc', 'power');
plot(f5, pow2db(pxx5));
hold on
[pxx6, f6] = pwelch(x3ReIm, [], [], 256, 3, 'centerdc', 'power');
plot(f6, pow2db(pxx6));
title('Signal Spectrum');
%legend({ 'y1(M = 1)', 'y2(M = 2)', 'y3(M = 3)', 'x(M = 1)', 'x2(M = 2)', 'x3(M = 3)'} ,'Location', 'southwest');