namespace DesignPattern
{
    public class 场所 { }

    public class 图书馆 : 场所 { }

    public class 体育馆 : 场所 { }

    public class 理科图书馆 : 图书馆 { }

    public class 文科图书馆 : 图书馆 { }

    public class PlaceFactory<TLibrary, TGym> where TLibrary : 图书馆, new() where TGym : 体育馆, new()
    {
        public TLibrary Create图书馆() => new TLibrary();

        public TGym Create体育馆() => new TGym();

        private static PlaceFactory<TLibrary, TGym> instance;

        /// <summary>
        /// 单例地点工厂
        /// </summary>
        public static PlaceFactory<TLibrary, TGym> Instance => instance ?? (instance = new PlaceFactory<TLibrary, TGym>());
    }
}
