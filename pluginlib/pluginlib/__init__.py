from importlib.metadata import entry_points


class PluginlibError(RuntimeError):
    pass


class ClassLoaderError(PluginlibError):
    pass


class ClassLoader:
    def __init__(self, package_name, base_class_name):
        self.package = package_name
        self.base_class = base_class_name
        self.entry_point_str = f'{self.package}.{self.base_class}'
        self.entry_points = {}

    def _load_entry_points(self):
        for ep in entry_points().get(self.entry_point_str, []):
            self.entry_points[ep.name] = ep

    def get_class(self, lookup_name):
        if not self.entry_points or lookup_name not in self.entry_points:
            self._load_entry_points()

        if lookup_name not in self.entry_points:
            available = ', '.join(self.get_available_plugins())
            raise ClassLoaderError(
                f'pluginlib cannot load class {repr(lookup_name)}. Available classes are {available}')

        return self.entry_points[lookup_name].load()

    def create_instance(self, lookup_name, *args, **kwargs):
        cls_type = self.get_class(lookup_name)
        return cls_type(*args, **kwargs)

    def get_available_plugins(self):
        if not self.entry_points:
            self._load_entry_points()

        return sorted(self.entry_points.keys())

    # Just to match the C++ version
    get_declared_classes = get_available_plugins
