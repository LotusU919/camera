#include	"camera.h"

// **カメラのX座標（外部から直接変更させない）**
static int CameraX = 0;
// **カメラのX座標（前フレーム）**
static int PreviousCameraX = 0;

// **カメラの初期化**
void InitCamera()
{
    CameraX = 0;
    PreviousCameraX = 0;
}

// **カメラの更新**
void UpdateCamera(float playerX)
{
    PreviousCameraX = CameraX;  // **前回のカメラ位置を保存**

    int playerCenterX = (int)roundf(playerX);
    int screenHalfWidth = SCREEN_LIMIT_RIGHT / 3;  // 全角対応

    // カメラの移動を制限
    if (abs(playerCenterX - CameraX) > screenHalfWidth)
    {
        CameraX = playerCenterX - screenHalfWidth;
    }

    // **カメラがマップ範囲を超えないように制限**
    int maxCameraX = VIRTUAL_MAP_WIDTH - SCREEN_LIMIT_RIGHT / 2;
    if (CameraX < 0)
    {
        CameraX = 0;
    }
    else if (CameraX > maxCameraX)
    {
        CameraX = maxCameraX;
    }
}

// **カメラのX座標を取得**
int GetCameraX()
{
    return CameraX;
}

int GetPreviousCameraX()
{
    return PreviousCameraX;
}