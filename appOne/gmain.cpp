#include"libOne.h"
void gmain() {
    window(1080, 1080, full);
    VECTOR2 Pos(0, 0);
    VECTOR2 Vel(0, 10);
    float MaxSpeed(10);
    float MaxForce(5);
    float NearDist(10);
    colorMode(HSV);
    while (notQuit) {
        clear(); noStroke(); fill(0, 0, 64); rect(0, 0, width, height);
        mathAxis(30.0f,128);

        if (isTrigger(KEY_Q))MaxSpeed += 1;
        if (isTrigger(KEY_A))MaxSpeed -= 1;
        if (isTrigger(KEY_W))MaxForce += 1;
        if (isTrigger(KEY_S))MaxForce -= 1;
        if (isTrigger(KEY_E))Vel.y += 1;
        if (isTrigger(KEY_D))Vel.y -= 1;
        if (isTrigger(KEY_SPACE))SetCursorPos(1920 / 2, 120);

        //加速度ベクトル acc （chase関数の中で計算する）
        VECTOR2 mouse(mathMouseX, mathMouseY);
        VECTOR2 acc = mouse - Pos;                                          strokeWeight(4); stroke(0, 50, 255); mathArrow(0, 0, acc.x, acc.y, 15);

        float dist = acc.mag();
        float speed = MaxSpeed;
        if (dist < NearDist) {
            speed = map(dist, 0, NearDist, 0, MaxSpeed);
        }
        acc.setMag(speed);                                                  strokeWeight(4); stroke(0, 100, 255); mathArrow(0, 0, acc.x, acc.y, 15);

        acc -= Vel;                                                         strokeWeight(4); stroke(0, 150, 255); mathArrow(Vel.x, Vel.y, Vel.x + acc.x, Vel.y + acc.y, 15);

        acc.limmit(MaxForce);                                               strokeWeight(8); stroke(0, 255, 255); mathArrow(Vel.x, Vel.y, Vel.x + acc.x, Vel.y + acc.y,25);
        
        
        //速度ベクトル Vel (move関数の中で計算する)
        VECTOR2 finalVel = Vel + acc;                                       strokeWeight(5); stroke(2, 255, 255); mathArrow(0, 0, finalVel.x, finalVel.y,20);
                                                                            strokeWeight(4); stroke(2, 100, 255); mathArrow(0, 0, Vel.x, Vel.y, 15);
        fill(0, 100, 255); print((let)"q-a MaxSpeed:" + MaxSpeed);
        fill(0, 255, 255); print((let)"w-s MaxForce:" + MaxForce);
        fill(0, 255, 255); print((let)"    acc.mag:" + acc.mag());
        fill(2, 100, 255); print((let)"e-d Vel.mag:" + Vel.mag());
        fill(2, 255, 255); print((let)"    fVel.mag:"+ finalVel.mag());
    }
}



