using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HadesState : MonoBehaviour
{
    public float HP;
    public float aggressivity=23;
    public float attacktime=0.2f;
    public MeshRenderer mesh;
    public WeaponAction weapon;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        switch (weapon.weaponnumber)
        {
            case 0:
                aggressivity = 23;
                break;
            case 1:
                aggressivity = 13;
                break;
        }     
    }
    public void Attacked()
    {
        attacktime -= Time.deltaTime;
        mesh.material.color = Color.red;
        if(attacktime<0)
        {
            mesh.material.color = Color.white;
            attacktime = 0.2f;
        }
    }
    public void HPDown(float x)
    {
        HP -= x;
    }
    public void Dead()
    {
        mesh.material.color = Color.red;
        Destroy(gameObject, 3f);
    }
}
