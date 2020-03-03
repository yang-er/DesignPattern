using System;
using System.Collections.Generic;
using System.Threading;

namespace DesignPattern
{
    public class ReuseableThread
    {
        private Action actionToExecute;
        private CancellationTokenSource waitingToken;

        public bool Free { get; private set; }

        public Thread Thread { get; }

        public void PushAction(Action action)
        {
            if (!Free || waitingToken == null)
                throw new InvalidOperationException("线程正处于工作状态。");
            actionToExecute = action;
            waitingToken.Cancel();
        }

        private static void ThreadManager(object param)
        {
            var manager = (ReuseableThread)param;
            while (manager.waitingToken.Token.WaitHandle.WaitOne())
            {
                if (manager.actionToExecute == null)
                    throw new InvalidOperationException();
                var action = manager.actionToExecute;
                manager.actionToExecute = null;
                manager.Free = false;
                manager.waitingToken = null;

                // 执行线程核心操作
                action.Invoke();

                manager.waitingToken = new CancellationTokenSource();
                manager.Free = true;
            }
        }

        public ReuseableThread()
        {
            Thread = new Thread(ThreadManager);
            Thread.Start(this);
        }
    }

    public class ThreadPool
    {
        private ReuseableThread[] Threads { get; }

        public ThreadPool(int N = 10)
        {
            Threads = new ReuseableThread[N];
            for (int i = 0; i < N; i++)
                Threads[i] = new ReuseableThread();
        }

        public void Apply(Action toRun)
        {
            for (int i = 0; i < Threads.Length; i++)
                if (Threads[i].Free)
                    Threads[i].PushAction(toRun);
            throw new InvalidOperationException("线程池中没有空闲进程。");
        }

        static Dictionary<string, ThreadPool> map = new Dictionary<string, ThreadPool>();

        // 线程池数量应该是比较少的，所以整体加锁
        public static ThreadPool GetInstance(string name = null)
        {
            name = name ?? "Default";

            lock (map)
            {
                if (map.ContainsKey(name))
                    return map[name];
                map.Add(name, new ThreadPool());
                return map[name];
            }
        }
    }
}
