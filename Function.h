#include "Constants.h"
class Function {
private:
    float x, y;
    metodo f1;
    float c1[2], c2[2];
    int dx, dy;
    float m;
    float steps;
    float pn;
    float Xinc, Yinc;
public:
    GLvoid drawing_stuff() {

        if (c1[0] != c2[0]) {
            m = (c2[1] - c1[1]) / (c2[0] - c1[0]);
            for (float i = c1[0]; i < c2[0]; i += 0.05) {
                y = m *( i + -c1[0])+c1[1];
                f1.Pinta_Pixel(i, y, 1, 1, 1);
            }
        }
        else {

            for (float i = c1[1]; i < c2[1]; i += 0.05) {

                f1.Pinta_Pixel(c1[0], i, 1, 1, 1);
            }
        }

    }
    GLvoid DDA() {

        dx = c2[0] - c1[0];
        dy = c2[1] - c1[1];
        if (abs(dx) >= abs(dy))
        steps = abs(dx);
        else
            steps = abs(dy);

        Xinc =(dx / steps);
        Yinc =(dy / steps);
        for (float i = 0; i < steps; i += 0.1) {

            x = c1[0] + Xinc * i;
            y = c1[1] + Yinc * i;
            f1.Pinta_Pixel(x, y, 128, 0, 128);
        }
    }
    GLvoid bresenham() {

        y = c1[1];
        x = c1[0];
        dx = c2[0] - c1[0];
        dy = c2[1] - c1[1];
        float pk = 2 * dy - dx;
        int i = 0;
        
        if (abs(dx) >= abs(dy)) {
            steps = abs(dx);
        }
        else {
            steps = abs(dy);
        }
        Xinc = (dx / steps);
        Yinc = (dy / steps);
        while (i <= steps) {

            if (pn < 0) {
                x = x + Xinc;
                y = y + Yinc;
                pn = pk + 2 * dy - 2 * dx;
            }
            else{

                x += Xinc;
                pn = pk + 2 * dy;
                
            }
            f1.Pinta_Pixel(x, y, 128, 0, 128);
            i++;
        }

    }
    GLvoid setc(int x1, int y1)
    {
        c1[0] = x1;
        c1[1] = y1;
    }
    GLvoid setc2(int x2, int y2)
    {
        c2[0] = x2;
        c2[1] = y2;
    }
};