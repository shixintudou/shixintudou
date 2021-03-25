using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class EnemyAttack : MonoBehaviour
{
    public Transform player;
    NavMeshAgent nav;
    private GameObject[] ways;
    private int way;
    private bool isfindway;
    public EnemyState state;
    public GameObject duang;
    public float duangtime = 2.5f;
    public bool isduanged = false;
    public HadesState hades;
    // Start is called before the first frame update
    void Start()
    {
        state = FindObjectOfType<EnemyState>();
        nav = GetComponent<NavMeshAgent>();
        ways = GameObject.FindGameObjectsWithTag("EditorOnly");
        way = Random.Range(0, ways.Length);
        nav.destination = (ways[way].transform.position);
        isfindway = true;
    }

    // Update is called once per frame
    void Update()
    {
        if(state.HP>0)
        {
            FinWay();
            AttakToHades();
        }       
    }

    private void FinWay()
    {
        if (nav == null)
            return;
        if(!state.dead)
        {
            if (Vector3.Distance(player.position, transform.position) >= 50)
            {
                if (isfindway)
                {
                    if (Vector3.Distance(ways[way].transform.position, transform.position) <= 4)
                    {
                        way = Random.Range(0, ways.Length);
                        nav.destination = ways[way].transform.position;
                    }
                }
                if (!isfindway)
                {
                    way = Random.Range(0, ways.Length);
                    nav.destination = (ways[way].transform.position);
                    isfindway = true;
                }
            }
            if (Vector3.Distance(player.position, transform.position) < 50)
            {
                nav.destination = player.position;
                isfindway = false;
            }
        }
    }
    private void AttakToHades()
    {
        switch(state.enemynumber)
        {
            case 0:
                if (Vector3.Distance(player.position, transform.position) < 30)
                {
                    nav.speed = 0f;
                }
                else
                    nav.speed = 15;
                break;
            case 1:
                if(Vector3.Distance(player.position, transform.position)<30)
                {
                    if(!isduanged)
                    {
                        duang.layer = 0;
                        duangtime -= Time.deltaTime;
                        if (Vector3.Distance(player.position, transform.position) < 10)
                            hades.duanged = true;
                        if(hades.duanged)
                        {
                            duang.layer = 2;
                            isduanged = true;
                        }
                        if (duangtime <= 2)
                        {
                            duang.layer = 2;
                            isduanged = true;
                        }
                    }
                    duangtime -= Time.deltaTime;
                    if(duangtime<=0)
                    {
                        isduanged = false;
                        duangtime = 2.5f;
                    }
                }
                break;
        }
    }
}