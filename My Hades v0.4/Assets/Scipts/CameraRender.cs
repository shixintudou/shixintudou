using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraRender : MonoBehaviour
{
    private Camera camera;
    public WeaponAction weapon;
    // Start is called before the first frame update
    void Start()
    {
        camera = GetComponent<Camera>();
    }

    // Update is called once per frame
    void Update()
    {
        
        if(weapon.weaponnumber==0)
        {
            if (weapon.isattack)
            {
                camera.cullingMask |= (1 << 8);
            }
            else
            {
                camera.cullingMask &= ~(1 << 8);
            }
            if (weapon.isspecial)
            {
                camera.cullingMask |= (1 << 10);
            }
            else
            {
                camera.cullingMask &= ~(1 << 10);
            }
        }
        if(weapon.weaponnumber==1)
        {
            if (weapon.isattack||weapon.isspecial)
            {
                camera.cullingMask |= (1 << 9);
            }
            else
            {
                camera.cullingMask &= ~(1 << 9);
            }
        }
    }
}
