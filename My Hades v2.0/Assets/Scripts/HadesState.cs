using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HadesState : MonoBehaviour
{
    public float HP;
    public float aggressivity=10f;
    public float attacktime=0.2f;
    public WeaponAction weapon;
    public MeshRenderer mesh;
    public bool isattacked = false;
    public bool missled = false;
    public bool duanged = false;
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
                aggressivity = 10;
                break;
            case 1:
                aggressivity = 6;
                break;
        }
        Attacked();
        Recover();
        if(missled)
        {
            HPDown(3);
            missled = false;
        }
        if(duanged)
        {
            HPDown(5);
            duanged = false;
        }
        if (HP <= 0)
            Dead();
    }
    public void Attacked()
    {
        if(isattacked)
        {
            mesh.material.color = Color.red;
            attacktime -= Time.deltaTime;
            if(attacktime<=0)
            {
                isattacked = false;
                attacktime = 0.2f;
            }
        }
    }
    public void HPDown(float x)
    {
        HP -= x;
    }
    public void Dead()
    {
        mesh.material.color = Color.red;
        Time.timeScale = 0;
        Application.Quit();
    }
    public void Recover()
    {
        if(!isattacked)
        mesh.material.color = Color.white;
    }
}
