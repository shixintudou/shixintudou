using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HadesState : MonoBehaviour
{
    public float HP;
    public float aggressivity;
    public float attacktime=0.2f;
    public MeshRenderer mesh;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
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
