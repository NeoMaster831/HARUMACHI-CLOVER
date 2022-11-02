#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

// argv[1] = dir
// argv[2] = 

char pixelToAscii(int alpha) {
	char ascii[16] = " .:l+1tvxO*#8@$";
	return ascii[alpha / 16];
}

int main(int argc, char* argv[]) { 

	if (argc < 4) {
		cout << "Usage: <image dir> <fx> <fy>" << '\n';
		return 1;
	}

	Mat img = imread(argv[1], IMREAD_GRAYSCALE);
	if (img.empty()) {
		cout << "Invalid directory" << endl;
		return 1;
	}

	Mat resizedImg;
	resize(img, resizedImg, Size(), atof(argv[2]), atof(argv[3]), INTER_NEAREST);

	for (int i = 0; i < resizedImg.rows; i++) {
		for (int j = 0; j < resizedImg.cols; j++) {
			uchar val = resizedImg.at<uchar>(i, j);
			cout << pixelToAscii((int)val);
		}
		cout << '\n';
	}

	return 0;
}