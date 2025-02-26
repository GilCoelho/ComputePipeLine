# ComputePipeline

This is a component that is responsible for performing a series of transformations on a **item** to
achieve a final result.

The component perform several action, starting always with an action of ```load``` of an **item** from storage.
The ```load``` will varied according the type of ```uri``` provided:
- The ```uri``` can be of a file path, starting with ```file://```;
- Of a qualified URL, starting with ```http://``` or ```https://```;
- Or a path pointing to an application bundle, starting with ```bundle://```.

After loading the **item**, will be processed by different actions, depending on its type.
- Images must be decoded;
- Compressed data must be decompressed;
- JSON must be turned into a _C++ object_.