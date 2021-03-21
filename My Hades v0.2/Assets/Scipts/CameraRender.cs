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
        if (weapon.isattack)
        {
            camera.cullingMask |= (1 << 8);
        }
        else
        {
            camera.cullingMask &= ~(1 << 8);
        }
        if(weapon.isspecial)
        {
            camera.cullingMask |= (1 << 10);
        }
        else
        {
            camera.cullingMask &= ~(1 << 10);
        }
    }
}
