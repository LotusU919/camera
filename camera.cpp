#include	"camera.h"

// **�J������X���W�i�O�����璼�ڕύX�����Ȃ��j**
static int CameraX = 0;
// **�J������X���W�i�O�t���[���j**
static int PreviousCameraX = 0;

// **�J�����̏�����**
void InitCamera()
{
    CameraX = 0;
    PreviousCameraX = 0;
}

// **�J�����̍X�V**
void UpdateCamera(float playerX)
{
    PreviousCameraX = CameraX;  // **�O��̃J�����ʒu��ۑ�**

    int playerCenterX = (int)roundf(playerX);
    int screenHalfWidth = SCREEN_LIMIT_RIGHT / 3;  // �S�p�Ή�

    // �J�����̈ړ��𐧌�
    if (abs(playerCenterX - CameraX) > screenHalfWidth)
    {
        CameraX = playerCenterX - screenHalfWidth;
    }

    // **�J�������}�b�v�͈͂𒴂��Ȃ��悤�ɐ���**
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

// **�J������X���W���擾**
int GetCameraX()
{
    return CameraX;
}

int GetPreviousCameraX()
{
    return PreviousCameraX;
}