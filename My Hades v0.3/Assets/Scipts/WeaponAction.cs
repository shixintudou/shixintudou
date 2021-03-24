using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WeaponAction : MonoBehaviour
{
    public Animation[] animation;
    private float attacktime = 0.2f;
    public GameObject[] Weapons;
    public bool isattack = false;
    public bool isspecial = false;
    private float specialtime = 0.3f;
    public int weaponnumber = 0;
    public string[] names = { "Sword", "Spear" };
    public Transform hades;
    private GameObject clone;
    public bool iscloned = false;
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
            animation[weaponnumber].Play(names[weaponnumber]);
            attacktime -= Time.deltaTime;
            Weapons[weaponnumber].layer = 0;
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
                    animation[weaponnumber].Play(names[weaponnumber]);
                    specialtime -= Time.deltaTime;
                    if (Mathf.Abs(specialtime) <= 0.02f)
                    {
                        specialtime = 0.3f;
                        isspecial = false;
                    }
                }
                break;
            case 1:
                       
                if (Input.GetKeyDown(KeyCode.Q) && !isattack)
                {
                    isspecial = true;
                    if (!iscloned)
                    {
                        clone = Instantiate(Weapons[weaponnumber]);
                        clone.transform.position = transform.position;
                        iscloned = true;
                    }
                }
                if(isspecial&&!isattack)
                {
                    if(Vector3.Distance(clone.transform.position,hades.position)<70)
                    clone.transform.Translate(transform.forward * Time.deltaTime * 60f);
                    if(Input.GetKeyDown(KeyCode.Q))
                    {
                        if(Vector3.Distance(clone.transform.position, hades.position) > 3)
                        {
                            Vector3 vector = hades.position - clone.transform.position;
                            clone.transform.Translate(vector * Time.deltaTime * 100f);
                        }
                        else
                        {
                            
                            iscloned = false;
                        }
                    }
                }
                break;
        }
                
     }
}
