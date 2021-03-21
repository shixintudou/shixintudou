using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyState : MonoBehaviour
{
    // Start is called before the first frame update
    public float HP = 50f;
    public bool beattacked = false;
    private float hurttime = 0.1f;
    GameObject enemy;
    public void Behurt()
    {
        hurttime -= Time.deltaTime;
        GetComponent<MeshRenderer>().material.color = Color.red;
        if (hurttime <= 0)
        {
            GetComponent<MeshRenderer>().material.color = Color.white;
            hurttime = 0.1f;
        }     
    }
    public void Dead()
    {
        GetComponent<MeshRenderer>().material.color = Color.red;
        Destroy(enemy, 3f);
    }
    public void HPdown(float hurt)
    {
        HP -= hurt;
    }
    // Update is called once per frame
}
