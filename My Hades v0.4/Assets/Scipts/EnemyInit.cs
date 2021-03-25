using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyInit : MonoBehaviour
{
    // Start is called before the first frame update
    public Transform []ways;
    GameObject[] enemys;
    int[] index;
    void Start()
    {
        InitEnemyposition();
    }

    private void InitEnemyposition()
    {
        enemys = GameObject.FindGameObjectsWithTag("Shootable");
        index = new int[enemys.Length];
        bool[] book = new bool[ways.Length];
        for (int i = 0; i < ways.Length; i++)
        {
            book[i] = false;
        }
        for (int i = 0; i < index.Length; i++)
        {
            int t = Random.Range(0, ways.Length);
            if (book[t] == false)
            {
                index[i] = t;
                book[t] = true;
            }
        }
        for (int i = 0; i < index.Length; i++)
        {
            enemys[i].GetComponent<CharacterController>().Move(ways[index[i]].transform.position);
        }
    }


    // Update is called once per frame
    void Update()
    {

    }
}
