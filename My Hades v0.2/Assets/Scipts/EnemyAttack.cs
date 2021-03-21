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
    // Start is called before the first frame update
    void Start()
    {
        nav = GetComponent<NavMeshAgent>();
        ways = GameObject.FindGameObjectsWithTag("EditorOnly");
        way = Random.Range(0, ways.Length);
        nav.destination = (ways[way].transform.position);
        isfindway = true;
    }

    // Update is called once per frame
    void Update()
    {
        if (Vector3.Distance(player.position, transform.position) >= 50)
        {
            if(isfindway)
            {
                if (Vector3.Distance(ways[way].transform.position, transform.position) <= 4)
                {
                    way = Random.Range(0, ways.Length);
                    nav.destination = ways[way].transform.position;
                }
            }
            if(!isfindway)
            {
                way = Random.Range(0, ways.Length);
                nav.destination = (ways[way].transform.position);
                isfindway = true;
            }                      
        }
        if (Vector3.Distance(player.position,transform.position)<50)
        {
            nav.destination = player.position;
            isfindway = false;
        }
    }
}