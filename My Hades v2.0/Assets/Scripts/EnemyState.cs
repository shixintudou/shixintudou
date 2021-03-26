using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class EnemyState : MonoBehaviour
{
    // Start is called before the first frame update
    public float HP ;
    public bool beattacked = false;
    public bool bespecialattacked = false;
    public bool bemissled = false;
    public bool dead;
    private float hurttime = 0.1f;
    public HadesState hades;
    public int enemynumber;
    private void Start()
    {
        hades = FindObjectOfType<HadesState>();
        if (HP == 100f)
            enemynumber = 0;
        if (HP == 400f)
            enemynumber = 1;
    }
    public void Behurt()
    {
        GetComponent<MeshRenderer>().material.color = Color.red;   
    }
    public void Dead()
    {
        if(dead)
        {
            GetComponent<MeshRenderer>().material.color = Color.red;
            Destroy(GetComponent<CharacterController>());
            GetComponentInChildren<Transform>().GetChild(0).gameObject.layer = 2;
            gameObject.layer = 2;
        }            
    }
    public void HPdown(float hurt)
    {        
            HP -= hurt;      
    }
    public void HurtRcover()
    {
        GetComponent<MeshRenderer>().material.color = Color.white;
        beattacked = false;
    }
    public void Bespecial()
    {
        GetComponent<MeshRenderer>().material.color = Color.red;
    }
    void Update()
    {
        if(beattacked)
        {
            hurttime -= Time.deltaTime;
            Behurt();
            if(hurttime<=0)
            {
                HPdown(hades.aggressivity);
                HurtRcover();
                hurttime = 0.1f;
                beattacked = false;
            }
            
        }
        if(bespecialattacked)
        {
            hurttime -= Time.deltaTime;
            Behurt();
            if(hurttime<=0)
            {
                HPdown(2.5f * hades.aggressivity);
                HurtRcover();
                hurttime = 0.1f;
                bespecialattacked = false;
            }           
            
        }
        if (bemissled)
        {
            hurttime -= Time.deltaTime;
            Behurt();
            if (hurttime <= 0)
            {
                HPdown(2.5f * hades.aggressivity);
                HurtRcover();
                hurttime = 0.1f;
                bemissled = false;
            }
        }
        if (HP<=0)
        {
            dead = true;
            Dead();
            dead = false;
        }
    }
    // Update is called once per frame
}
