using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WeaponAction : MonoBehaviour
{
    public Animation animation;
    private float attacktime = 0.2f;
    public GameObject[] Weapons;
    public bool isattack = false;
    public bool isspecial = false;
    private float specialtime = 0.3f;
    public int weaponnumber = 0;
    public Transform hades;
    public GameObject clone;
    private Vector3 vector1;
    private Vector3 vector;
    public bool isout = false;
    public bool isback = true;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        WeaponComeout();
        SpecialAttack();
        if (Input.GetKeyDown(KeyCode.E))
            weaponnumber = (weaponnumber + 1) % 2;
    }

    private void WeaponComeout()
    {

        if (Input.GetMouseButtonDown(0) && !isspecial)
        {
            isattack = true;
        }
        if (isattack && !isspecial)
        {
            //Weapons[weaponnumber].layer = 0;
            if(weaponnumber==0)
            animation.Play("Sword");
            attacktime -= Time.deltaTime;            
            if (Mathf.Abs(attacktime) <= 0.02f)
            {
                attacktime = 0.2f;
                isattack = false;
            }
        }
    }
     private void SpecialAttack()
     {
        switch (weaponnumber)
        {
            case 0:
                if (Input.GetKeyDown(KeyCode.Q) && !isattack)
                {
                    isspecial = true;
                }
                if (isspecial && !isattack)
                {
                    animation.Play("Sword");
                    specialtime -= Time.deltaTime;
                    if (Mathf.Abs(specialtime) <= 0.02f)
                    {
                        specialtime = 0.3f;
                        isspecial = false;
                    }
                }
                break;
            case 1:
                       
                if (Input.GetKeyDown(KeyCode.Q) && !isattack&&!isspecial)
                {
                    isspecial = true;                    
                    if(clone==null)
                    {
                        clone = Instantiate(Weapons[weaponnumber]);                       
                    }
                    clone.transform.position = hades.position + new Vector3(0, 0.1f, 0);
                    vector1 = transform.forward + new Vector3(0, 0.1f, 0);
                }
                if(isspecial&&!isattack)
                {                    
                    if(Vector3.Distance(clone.transform.position,hades.position)<70)
                    {
                        if(!isout)
                        {
                            clone.transform.LookAt(vector1);
                            clone.transform.Translate(vector1 * Time.deltaTime * 80f);
                            clone.transform.localScale = new Vector3(3, 3, 3);
                        }
                        if (Vector3.Distance(clone.transform.position, hades.position) >= 70)
                            isout = true;
                    }                   
                    if(Input.GetKeyDown(KeyCode.Q)&&isout)
                    {
                        isback = false;                        
                    }
                    if(!isback)
                    {
                        if (Vector3.Distance(clone.transform.position, hades.position) > 3)
                        {
                            vector = (hades.position + new Vector3(0, 0.1f, 0) - clone.transform.position).normalized;
                            clone.transform.LookAt(vector);
                            clone.transform.Translate(vector * Time.deltaTime*100f );
                        }
                        else
                        {
                            isout = false;
                            isspecial = false;
                            isback = true;
                        }
                    }
                }
                break;
        }
                
     }
}
