using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Tonext : MonoBehaviour
{
    public int number = 0;
    private EnemyState[] enemies;
    // Start is called before the first frame update
    private void Awake()
    {
        DontDestroyOnLoad(gameObject);
    }
    void Start()
    {
        enemies = FindObjectsOfType<EnemyState>();
    }

    // Update is called once per frame
    void Update()
    {
        if(LoadJudge()&&enemies!=null)
        {
            SceneManager.LoadScene((number) % 2 + 1);
            number++;
            enemies = FindObjectsOfType<EnemyState>();
        }
        enemies = FindObjectsOfType<EnemyState>();
    }
    private bool LoadJudge()
    {
        foreach(EnemyState i in enemies)
        {
            if (i.HP > 0)
                return false;
        }
        return true;
    }
}
