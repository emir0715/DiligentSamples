/*     Copyright 2015-2019 Egor Yusov
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF ANY PROPRIETARY RIGHTS.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#pragma once

namespace Diligent
{
    
class InputControllerWin32
{
public:
    InputControllerWin32(bool SmoothMouseMotion = false);

    bool HandleNativeMessage(const void* MsgData);

    const MouseState& GetMouseState();

    INPUT_KEY_STATE_FLAGS GetKeyState(InputKeys Key)const
    {
        return m_Keys[static_cast<size_t>(Key)];
    }

private:
    INPUT_KEY_STATE_FLAGS m_Keys[static_cast<size_t>(InputKeys::TotalKeys)] = {};  // State of input - KEY_WAS_DOWN_MASK | KEY_IS_DOWN_MASK

    static bool IsKeyDown(Uint8 key);
    static bool WasKeyDown(Uint8 key);
    void UpdateMouseDelta();

    Uint32 m_NumKeysDown = 0;
    Int32 m_LastMousePosX = 0;
    Int32 m_LastMousePosY = 0;

    const bool m_SmoothMouseMotion;

    MouseState m_MouseState;
};

}
