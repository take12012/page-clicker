#include <M5StickCPlus2.h>
#include <BleMouse.h>
#include <M5Unified.h>

BleMouse bleMouse("Pointer");

// 初期設定
void setup() {
  // 本体初期化
  auto cfg = M5.config();
  StickCP2.begin(cfg);
  // マウス初期化
  bleMouse.begin();

  // 画面の初期設定
  M5.Lcd.setTextSize(2);                             // 文字サイズ（整数倍率）
  M5.Lcd.setCursor(0, 0);                            // 座標設定(x, y)
  int bat_level = StickCP2.Power.getBatteryLevel();  // バッテリーの状態を取得
  M5.Lcd.printf("%d% %% \n\n", bat_level);
  M5.Lcd.println("Controller");
  M5.Lcd.println(" BtnA: ->");
  M5.Lcd.println(" BtnB: <-");
}

// メイン処理
void loop() {
  // 本体ボタンの状態更新
  M5.update();

  // マウス操作
  if (bleMouse.isConnected()) {
    if (M5.BtnA.wasReleased()) {
      Serial.println("Send Scroll down");
      bleMouse.move(0, 0, -1);
    }

    if (M5.BtnB.wasReleased()) {
      Serial.println("Send Scroll up");
      bleMouse.move(0, 0, 1);
    }
  }
}