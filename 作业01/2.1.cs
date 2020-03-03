namespace DesignPattern
{
    public class 场所 { }

    public class 图书馆 : 场所 { }

    public class 体育馆 : 场所 { }

    public class 理科图书馆 : 图书馆 { }

    public class 文科图书馆 : 图书馆 { }

    public interface IPlaceFactory
    {
        场所 Create场所();
    }

    public interface IPlaceFactory<out T> : IPlaceFactory where T : 场所
    {
        new T Create场所();
    }

    public class PlaceFactory<T> : IPlaceFactory<T> where T : 场所, new()
    {
        public T Create场所() => new T();

        场所 IPlaceFactory.Create场所() => Create场所();
    }
}
