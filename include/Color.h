#ifndef COLOR_H
#define COLOR_H

class Color {
	private:
		int red;
		int green;
		int blue;
    public:
        Color();
        ~Color();

		void setColor(int red, int green, int blue);

		int getColorRed();
		int getColorGreen();
		int getColorBlue();
};

#endif
